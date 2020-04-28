#include "record64.h"
#include "lame.h"
#include "MD5.h"
//#include "Voice.h"

#include <io.h>
#include <stdio.h>

#include <QFileDialog>
#include <QMessageBox>  
#include <QJsonDocument>
#include <QJsonObject>
#include <QtNetwork/QHttpMultiPart>
#include <QJsonArray>
#include <QTextCodec>
#include <QButtonGroup>


#include <string>
using namespace std;


record64::record64(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	m_bstart_record = false;
	m_bend_record = false;
	m_bstart_listen = false;
	m_bwrite = false;
	m_taskid = "";
	m_iprovider = 2;

	m_realtime_count = 0;
	ui.m_samplerate_16k->setChecked(true);
	//ui.m_bit16->setChecked(true);
	ui.m_mono->setChecked(true);
	ui.m_single_mac->setChecked(true);
	ui.m_random->setChecked(true);
	ui.m_one_person->setChecked(true);
	ui.m_xunfei->setChecked(true);

	ui.m_curr_status->setText(QString::fromLocal8Bit("初始状态"));
	ui.m_path->setEnabled(false);
	m_appid = m_config.Get("user", "appid").toString();
	m_secretKey = m_config.Get("user", "secretKey").toString();
	m_imac_num = m_config.Get("user", "mac_num").toInt();
	if (m_imac_num != 1 && m_imac_num != 2)
		m_imac_num = 2;
	
	m_token = m_config.Get("user","token").toString();
	m_listen_basepath = m_config.Get("user","listen_file_path").toString();

	m_recognize_basepath = m_config.Get("voice","basepath").toString();
	RadioButton_Group();

	//m_presult.qestion = "";
	//m_presult.qledit = nullptr;
	m_ple = nullptr;
	m_qscurr = "";

	m_baidu_return = true;
	m_ibpos = 44;

	init_info();
	m_curr = nullptr;
	//m_pvoice = nullptr;
	m_upload_file = nullptr;
	m_record_dll.set_islog(true);

	connect(ui.m_bt_setpath, SIGNAL(clicked()), this, SLOT(set_path()));
	connect(ui.m_btstart_record, SIGNAL(clicked()), this, SLOT(start_record()));
	connect(ui.m_btstop_record, SIGNAL(clicked()), this, SLOT(end_record()));
	connect(ui.m_bt_recognize, SIGNAL(clicked()), this, SLOT(recognize_voice()));
	//connect(ui.m_bt_recognize, SIGNAL(clicked()), this, SLOT(recognize_baidu()));
	connect(ui.m_baidu, SIGNAL(clicked()), this, SLOT(select_baidu()));
	connect(ui.m_xunfei, SIGNAL(clicked()), this, SLOT(select_xunfei()));

	connect(ui.m_btstart_listen, SIGNAL(clicked()), this, SLOT(start_listen()));
	connect(ui.m_btstop_listen, SIGNAL(clicked()), this, SLOT(stop_listen()));
}

record64::~record64()
{
	if (m_curr) 
	{
		delete m_curr;
		m_curr = nullptr;
	}

	//if (m_pvoice)
	//{
	//	delete m_pvoice;
	//	m_pvoice = nullptr;
	//}

	if (m_upload_file)
	{
		delete m_upload_file;
		m_upload_file = nullptr;
	}
}

void record64::closeEvent(QCloseEvent* e)
{
	end_record();
}

//begin slots functions
//read_more
/*void record64::read_more()
{
	if (nullptr == m_fp_record)
	{
		QString spath = "";
	    spath = ui.m_path->text() + "/" + ui.m_name->text() + ".wav";
		
		m_fp_record = fopen(spath.toLocal8Bit(),"wb");
	}

	//QByteArray m_buffer(2048, 0);
	qint64 len = _audioInput->bytesReady();
	char* m_buffer = new char[len + 1];
	qint64 l = m_buffin->read(m_buffer, len);
	fwrite(m_buffer, 1, len, m_fp_record);
	delete []m_buffer;
}*/

void record64::set_path()
{
	QString dirpath = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("选择目录"), "./", QFileDialog::ShowDirsOnly);
	if (dirpath != "")
		ui.m_path->setText(dirpath);
}

//开始录音
void record64::start_record()
{
	if (m_bstart_listen)
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在监听，请先结束监听状态"));
		return;
	}

	if (m_bstart_record)   //已经开始录音
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在录音，请先停止录音"));
		return;
	}

	if ("" == ui.m_path->text() || "" == ui.m_name->text())
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("路径或文件名不能为空"));
		return;
	}

	m_record_path = ui.m_path->text();
	m_record_name = ui.m_name->text();

	m_bstart_record = true;
	m_bend_record = false;
	m_ibpos = 44;

	//record_voice();
	
	ui.m_te_result->setText("");

	QString record_path = ui.m_path->text() + "/" + ui.m_name->text() + ".wav";
	int iret = m_record_dll.start_record(record_path);
	if(0 == iret)
		ui.m_curr_status->setText(QString::fromLocal8Bit("正在录音"));

	/*int iret = 0;
	if (ui.m_baidu->isChecked())
	{
		m_record_dll.set_baidu_token("24.8fe58964072d84f6a7fc8bcd898850ac.2592000.1585219010.282335-18578469");
		m_record_dll.set_channelnum(1);
		iret = m_record_dll.start_listen(1);
	}
	else if (ui.m_xunfei->isChecked())
	{
		m_record_dll.set_xunfei_appid(m_appid);
		m_record_dll.set_xunfei_secretkey(m_secretKey);
		iret = m_record_dll.start_listen(2);
	}

	if (0 == iret)
	{
		m_listen_timer = new QTimer();
		m_listen_timer->setSingleShot(false);

		//启动或重启定时器, 并设置定时器时间：毫秒   
		m_listen_timer->start(2000);

		//定时器触发信号槽   
		connect(m_listen_timer, SIGNAL(timeout()), this, SLOT(listen_get_result()));

		ui.m_curr_status->setText(QString::fromLocal8Bit("正在录音"));
	}
	*/	
}

//停止录音
void record64::end_record()
{
	if (!m_bstart_record)
		return;
	m_record_dll.end_record();
	//m_record_dll.stop_listen();

	//m_recognize_file = QString::fromLocal8Bit(sinpath.c_str());
	//m_baidu_rec_file = QString::fromLocal8Bit(sinpath.c_str());
	QString record_path = ui.m_path->text() + "/" + ui.m_name->text() + ".wav";
	m_recognize_file = record_path;
	m_baidu_rec_file = record_path;
	m_bend_record = true;
	m_bstart_record = false;

	ui.m_curr_status->setText(QString::fromLocal8Bit("录音结束"));
}

//开始监听语音
void record64::start_listen()
{
	if (m_bstart_record)   //已经开始录音
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在录音，请先结束录音状态"));
		return;
	}

	if (m_bstart_listen)   //正在监听
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("正在监听语音，请先结束监听，再开始"));
		return;
	}

	m_bstart_listen = true;
	
	int iret = 0;
	if (ui.m_baidu->isChecked())
	{
		m_record_dll.set_baidu_token(m_token);//"24.8fe58964072d84f6a7fc8bcd898850ac.2592000.1585219010.282335-18578469"
		m_record_dll.set_channelnum(1);
		iret = m_record_dll.start_listen(1);
	}
	else if (ui.m_xunfei->isChecked())
	{
		m_record_dll.set_xunfei_appid(m_appid);
		m_record_dll.set_xunfei_secretkey(m_secretKey);
		iret = m_record_dll.start_listen(2);
	}

	if (0 == iret)
	{
		m_listen_timer = new QTimer();
		m_listen_timer->setSingleShot(false);

		//启动或重启定时器, 并设置定时器时间：毫秒
		m_listen_timer->start(2000);

		//定时器触发信号槽
		connect(m_listen_timer, SIGNAL(timeout()), this, SLOT(listen_get_result()));

		ui.m_curr_status->setText(QString::fromLocal8Bit("正在进行语音监听"));
		return;
	}

	ui.m_curr_status->setText(QString::fromLocal8Bit("语音监听失败"));	
}

//结束监听语音
void record64::stop_listen()
{
	if (!m_bstart_listen)
		return;

	if (m_listen_timer)
	{
		m_listen_timer->stop();
		delete m_listen_timer;
		m_listen_timer = nullptr;
	}

	if (m_bstart_listen)
	{
		m_bstart_listen = false;
		m_record_dll.stop_listen();
		//return;
	}
	
	m_bwrite = false;
	ui.m_curr_status->setText(QString::fromLocal8Bit("结束语音监听"));
	return;
}

//语音识别
void record64::recognize_voice()
{
	if (!m_bstart_record && !m_bend_record)
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("还没有录音"));
		return;
	}

	if (m_bstart_record && !m_bend_record)
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先停止录音"));
		return;
	}
	
	ui.m_te_result->setText("");

	if (1 == m_iprovider)
		recognize_baidu();
	else if (2 == m_iprovider)
	{
		//初始化乳房部位是否被描述过的 结构信息
		init_breast_rt_info();

		m_record_dll.set_xunfei_appid(m_appid);
		m_record_dll.set_xunfei_secretkey(m_secretKey);
		int iret = m_record_dll.recognize_xunfei(m_recognize_file);
		if (0 == iret)
		{
			m_xunfei_timer = new QTimer(this);
			m_xunfei_timer->setSingleShot(true);

			//启动或重启定时器, 并设置定时器时间：毫秒   
			m_xunfei_timer->start(3000);

			//定时器触发信号槽   
			connect(m_xunfei_timer, SIGNAL(timeout()), this, SLOT(get_xunfei_result()));

		}
		ui.m_curr_status->setText(QString::fromLocal8Bit("正在进行语音识别"));
	}    
}

void record64::recognize_baidu()
{
	if (!m_bstart_record && !m_bend_record)
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("还没有录音"));
		return;
	}

	if (m_bstart_record && !m_bend_record)
	{
		QMessageBox::critical(0, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请先停止录音"));
		return;
	}

	//初始化乳房部位是否被描述过的 结构信息
	init_breast_rt_info();

	m_record_dll.set_baidu_token(m_token);//"24.8fe58964072d84f6a7fc8bcd898850ac.2592000.1585219010.282335-18578469"
	int iret = m_record_dll.recognize_baidu(m_baidu_rec_file);
	if (0 == iret)
	{
		m_baidu_timer = new QTimer(this);
		m_baidu_timer->setSingleShot(true);

		//启动或重启定时器, 并设置定时器时间：毫秒   
		m_baidu_timer->start(1000);

		//定时器触发信号槽   
		connect(m_baidu_timer, SIGNAL(timeout()), this, SLOT(get_baidu_result()));

	}
	ui.m_curr_status->setText(QString::fromLocal8Bit("正在进行语音识别"));
}

void record64::select_baidu()
{
	ui.m_samplerate_44k->setEnabled(false);
	ui.m_samplerate_16k->setEnabled(true);
	ui.m_samplerate_8k->setEnabled(false);
	ui.m_samplerate_16k->setChecked(true);

	ui.m_mono->setEnabled(true);
	ui.m_stereo->setEnabled(false);
	ui.m_mono->setChecked(true);

	ui.m_single_mac->setEnabled(true);
	ui.m_double_mac->setEnabled(true);
	ui.m_single_mac->setChecked(false);

	ui.m_one_person->setEnabled(false);
	ui.m_two_person->setEnabled(false);

	ui.m_random->setEnabled(true);
	ui.m_template->setEnabled(false);
	ui.m_random->setChecked(true);

	m_iprovider = 1;
}

void record64::select_xunfei()
{
	ui.m_samplerate_44k->setEnabled(true);
	ui.m_samplerate_16k->setEnabled(true);
	ui.m_samplerate_8k->setEnabled(true);

	ui.m_mono->setEnabled(true);
	ui.m_stereo->setEnabled(true);

	ui.m_single_mac->setEnabled(true);
	ui.m_double_mac->setEnabled(true);

	ui.m_one_person->setEnabled(true);
	ui.m_two_person->setEnabled(true);

	ui.m_random->setEnabled(true);
	ui.m_template->setEnabled(true);

	m_iprovider = 2;
}

void record64::listen_get_result()
{
	vector<QString> vresult;
	m_record_dll.get_listen_result(vresult);

	QString content = "";
	for (auto it : vresult)
	{
		content += it;
		content += " ";

		if (m_bwrite == false)
		{
			//if (it == QString::fromLocal8Bit("开始录音"))
			if (compare_result(v_start_info, it))
			{
				QMessageBox Msg(QMessageBox::Question, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("可以开始"));
				QAbstractButton* pYesBtn = (QAbstractButton*)Msg.addButton(QString::fromLocal8Bit("是"), QMessageBox::YesRole);
				Msg.exec();
				
				m_bwrite = true;

				//初始化乳房部位是否被描述过的 结构信息
				init_breast_rt_info();

				QString listen_name = "";
				time_t now_time = time(NULL);
				tm* ptm = localtime(&now_time);

				char ch_time[32];
				memset(ch_time, 0, 32);
				sprintf(ch_time, "%04d%02d%02d_%02d%02d%02d", \
					ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, \
					ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

				listen_name = ch_time;
				listen_name += ".wav";
				QString path = m_listen_basepath + "/" + listen_name;
				m_record_dll.write_listen_file(path);
				break;
			}
		}
		else if (true == m_bwrite)
		{
			if (compare_result(v_end_info, it))
			{
				QMessageBox Msg(QMessageBox::Question, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("已经结束"));
				QAbstractButton* pYesBtn = (QAbstractButton*)Msg.addButton(QString::fromLocal8Bit("是"), QMessageBox::YesRole);
				Msg.exec();
				
				m_bwrite = false;
				m_record_dll.stop_listen();

				if (m_listen_timer)
				{
					m_listen_timer->stop();
					delete m_listen_timer;
					m_listen_timer = nullptr;
				}

				if (m_bstart_listen)
				{
					m_bstart_listen = false;
					m_record_dll.stop_listen();
				}

				ui.m_curr_status->setText(QString::fromLocal8Bit("结束语音监听"));
				ui.m_te_errinfo->setText(QString::fromLocal8Bit("无"));

				set_other_breast_info();
				break;
			}
			
			parse_listen_result(it);
		}
	}

	QString spre = ui.m_te_result->toPlainText();
	content = spre + content;
	ui.m_te_result->setText(content);
}
//end slots functions

//begin private functions
void record64::out_errinfo(QString errinfo, int istep)
{
	QString info = "";
	info = errinfo; //QString::fromLocal8Bit(errinfo.toUtf8().data());
	switch (istep)
	{
	case recognize_step::prepare:
	{
		info += "in prepare";
		ui.m_te_errinfo->setText(info);
	}
	break;
	case recognize_step::upload:
	{
		info += "in upload";
		ui.m_te_errinfo->setText(info);
	}
	break;
	case recognize_step::merge:
	{
		info += "in merge";
		ui.m_te_errinfo->setText(info);
	}
	break;
	case recognize_step::get_result:
	{
		info += "in get_result";
		ui.m_te_errinfo->setText(info);
	}
	break;
	default:
		ui.m_te_errinfo->setText(info);
		break;

	}
}

void record64::bak_voice_file(QString filename)
{
	QString mp3_name = filename.left(filename.length() - 4);
	mp3_name += ".mp3";

	if (0 == _access(mp3_name.toLocal8Bit().data(), 00))   //文件存在
	{
		QString bak_name = "";
		time_t now_time = time(NULL);
		tm *ptm = localtime(&now_time);

		char ch_time[32];
		memset(ch_time, 0, 32);
		sprintf(ch_time, "_%04d%02d%02d_%02d%02d%02d",\
			    ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, \
			    ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

		bak_name = mp3_name.left(mp3_name.length()-4);
		bak_name += ch_time;
		bak_name += ".mp3";
		rename(mp3_name.toLocal8Bit().data(),bak_name.toLocal8Bit().data());
	}
}

int record64::get_sample_rate()
{
	if (ui.m_samplerate_44k->isChecked())
		return 44100;
	else if (ui.m_samplerate_16k->isChecked())
		return 16000;
	else //(ui.m_samplerate_8k->isChecked())
		return 8000;
}

int record64::get_channel_num()
{
	if (ui.m_mono->isChecked())
		return 1;
	else //(ui.m_stereo)
		return 2;
}

int record64::get_mac_num()
{
	if (ui.m_single_mac->isChecked())
		return 1;
	else //(ui.m_double_mac->isChecked())
		return 2;
}

int record64::get_speaker_num()
{
	if (ui.m_one_person->isChecked())
		return 1;
	else //(ui.m_two_person->isChecked())
		return 2;
}

int record64::get_speak_mode()
{
	if (ui.m_random->isChecked())
		return 1;
	else //(ui.m_template->isChecked())
		return 2;
}

void record64::RadioButton_Group()
{
	ml_rt_group = new QButtonGroup();
	ml_pf_group = new QButtonGroup();
	ml_yy_group = new QButtonGroup();
	ml_xt_group = new QButtonGroup();
	ml_fr_group = new QButtonGroup();
	ml_tt_group = new QButtonGroup();
	
	mr_rt_group = new QButtonGroup();
	mr_pf_group = new QButtonGroup();
	mr_yy_group = new QButtonGroup();
	mr_xt_group = new QButtonGroup();
	mr_fr_group = new QButtonGroup();
	mr_tt_group = new QButtonGroup();
	mrflx_group = new QButtonGroup();

	ml_rt_group->addButton(ui.ml_rt_normal);
	ml_rt_group->addButton(ui.ml_rt_up);
	ml_rt_group->addButton(ui.ml_rt_ax);
	ml_rt_group->addButton(ui.ml_rt_ml);

	ml_pf_group->addButton(ui.ml_pf_normal);
	ml_pf_group->addButton(ui.ml_pf_jwz);
	ml_pf_group->addButton(ui.ml_pf_jpy);
	ml_pf_group->addButton(ui.ml_pf_jy);

	ml_yy_group->addButton(ui.ml_yy_no);
	ml_yy_group->addButton(ui.ml_yy_single);
	ml_yy_group->addButton(ui.ml_yy_multi);
	ml_yy_group->addButton(ui.ml_yy_xx);
	ml_yy_group->addButton(ui.ml_yy_yellow);
	ml_yy_group->addButton(ui.ml_yy_ry);
	ml_yy_group->addButton(ui.ml_yy_qsy);

	ml_xt_group->addButton(ui.ml_xt_normal);
	ml_xt_group->addButton(ui.ml_xt_txz);
	ml_xt_group->addButton(ui.ml_xt_jxxzh);
	ml_xt_group->addButton(ui.ml_xt_zk);
	ml_xt_group->addButton(ui.ml_xt_jjxzh);

	ml_fr_group->addButton(ui.ml_fr_yes);
	ml_fr_group->addButton(ui.ml_fr_no);

	ml_tt_group->addButton(ui.ml_tt_dt);
	ml_tt_group->addButton(ui.ml_tt_jcxtt);
	ml_tt_group->addButton(ui.ml_tt_jqtt);
	ml_tt_group->addButton(ui.ml_tt_zt);
	ml_tt_group->addButton(ui.ml_tt_rt);
	ml_tt_group->addButton(ui.ml_tt_no);

	mr_rt_group->addButton(ui.mr_rt_normal);
	mr_rt_group->addButton(ui.mr_rt_up);
	mr_rt_group->addButton(ui.mr_rt_ax);
	mr_rt_group->addButton(ui.mr_rt_ml);

	mr_pf_group->addButton(ui.mr_pf_normal);
	mr_pf_group->addButton(ui.mr_pf_jwz);
	mr_pf_group->addButton(ui.mr_pf_jpy);
	mr_pf_group->addButton(ui.mr_pf_jy);

	mr_yy_group->addButton(ui.mr_yy_no);
	mr_yy_group->addButton(ui.mr_yy_single);
	mr_yy_group->addButton(ui.mr_yy_multi);
	mr_yy_group->addButton(ui.mr_yy_xx);
	mr_yy_group->addButton(ui.mr_yy_yellow);
	mr_yy_group->addButton(ui.mr_yy_ry);
	mr_yy_group->addButton(ui.mr_yy_qsy);

	mr_xt_group->addButton(ui.mr_xt_normal);
	mr_xt_group->addButton(ui.mr_xt_txz);
	mr_xt_group->addButton(ui.mr_xt_jxxzh);
	mr_xt_group->addButton(ui.mr_xt_zk);
	mr_xt_group->addButton(ui.mr_xt_jjxzh);

	mr_fr_group->addButton(ui.mr_fr_yes);
	mr_fr_group->addButton(ui.mr_fr_no);

	mr_tt_group->addButton(ui.mr_tt_dt);
	mr_tt_group->addButton(ui.mr_tt_jcxtt);
	mr_tt_group->addButton(ui.mr_tt_jqtt);
	mr_tt_group->addButton(ui.mr_tt_zt);
	mr_tt_group->addButton(ui.mr_tt_rt);
	mr_tt_group->addButton(ui.mr_tt_no);

	mrflx_group->addButton(ui.m_rf_zfx);
	mrflx_group->addButton(ui.m_rf_zmx);
}

void record64::init_info()
{
	init_rutou_info();
	init_pifu_info();
	init_yiye_info();
	init_xianti_info();
	init_furu_info();
	init_tengtong_info();
	init_rufang_type_info();
	init_start_end_info();
}

void record64::get_baidu_result()
{
	vector<QString> vbaidu;
	m_record_dll.get_result_baidu(vbaidu);

	if (0 == vbaidu.size())
	{
		delete m_baidu_timer;

		m_baidu_timer = new QTimer(this);
		m_baidu_timer->setSingleShot(true);

		//启动或重启定时器, 并设置定时器时间：毫秒   
		m_baidu_timer->start(1000);

		//定时器触发信号槽   
		connect(m_baidu_timer, SIGNAL(timeout()), this, SLOT(get_baidu_result()));
	}
	else
	{
		QString result = "";
		for (auto it_result : vbaidu)
		{
			result += it_result;
			result += " ";

			ui.m_te_result->setText(result);

			bool bneed = true;
			//部位和症状连着念的情况
			//比如 皮肤正常
			for (auto it : md_symptom_info)
			{
				if (compare_result(it->v_names, it_result))
				{
					set_breast_checked(it->index);

					if (it->pleft)
						it->pleft->setChecked(true);
					if (it->pright)
						it->pright->setChecked(true);
					bneed = false;
					break;
				}
			}

			//部位和症状分开念的情况
			//比如 皮肤  正常
			if (bneed)
			{
				if (m_curr == nullptr)
				{
					for (auto it : md_breast)
					{
						if (compare_result(it->v_names, it_result))
						{
							m_curr = it;
							break;
						}
					}
				}
				else
				{
					for (auto it : m_curr->vinfo)
					{
						if (compare_result(it->v_names, it_result))
						{
							set_breast_checked(it->index);

							if (it->pleft)
								it->pleft->setChecked(true);
							if (it->pright)
								it->pright->setChecked(true);

							m_curr = nullptr;
							break;
						}
					}
					//没有识别出来，设置默认值
					if (m_curr != nullptr)
					{
						set_breast_checked(m_curr->pdefault->index);

						if (m_curr->pdefault->pleft)
							m_curr->pdefault->pleft->setChecked(true);
						if (m_curr->pdefault->pright)
							m_curr->pdefault->pright->setChecked(true);

						m_curr = nullptr;

						//当没有识别出来 当前指向的具体内容时，再看一下是不是下一个指向的语音
						for (auto it : md_breast)
						{
							if (compare_result(it->v_names, it_result))
							{
								m_curr = it;
								break;
							}
						}
					}
				}
			}//end if (bneed)
		}//end for (auto it:vbaidu)

		ui.m_curr_status->setText(QString::fromLocal8Bit("识别结束"));
		ui.m_te_errinfo->setText(QString::fromLocal8Bit("无"));
		
		result = "";
		set_other_breast_info();

	}//end else

}

void record64::get_xunfei_result()
{
	vector<QString> vxunfei;
	int ret = m_record_dll.get_result_xunfei(vxunfei);
	if (-1 == ret)
	{
		delete m_xunfei_timer;

		m_xunfei_timer = new QTimer(this);
		m_xunfei_timer->setSingleShot(true);

		//启动或重启定时器, 并设置定时器时间：毫秒   
		m_xunfei_timer->start(2000);

		//定时器触发信号槽   
		connect(m_xunfei_timer, SIGNAL(timeout()), this, SLOT(get_xunfei_result()));
	}
	else
	{
		QString result = "";
		for (auto it_result : vxunfei)
		{
			result += it_result;
			result += " ";

			bool bneed = true;
			//部位和症状连着念的情况
			//比如 皮肤正常
			for (auto it : md_symptom_info)
			{
				if (compare_result(it->v_names, it_result))
				{
					set_breast_checked(it->index);

					if (it->pleft)
						it->pleft->setChecked(true);
					if (it->pright)
						it->pright->setChecked(true);
					bneed = false;
					break;
				}
			}

			//部位和症状分开念的情况
			//比如 皮肤  正常
			if (bneed)
			{
				if (m_curr == nullptr)
				{
					for (auto it : md_breast)
					{
						if (compare_result(it->v_names, it_result))
						{
							m_curr = it;
							break;
						}
					}
				}
				else
				{
					for (auto it : m_curr->vinfo)
					{
						if (compare_result(it->v_names, it_result))
						{
							set_breast_checked(it->index);

							if (it->pleft)
								it->pleft->setChecked(true);
							if (it->pright)
								it->pright->setChecked(true);

							m_curr = nullptr;
							break;
						}
					}
					//没有识别出来，设置默认值
					if (m_curr != nullptr)
					{
						set_breast_checked(m_curr->pdefault->index);

						if (m_curr->pdefault->pleft)
							m_curr->pdefault->pleft->setChecked(true);
						if (m_curr->pdefault->pright)
							m_curr->pdefault->pright->setChecked(true);

						m_curr = nullptr;

						//当没有识别出来 当前指向的具体内容时，再看一下是不是下一个指向的语音
						for (auto it : md_breast)
						{
							if (compare_result(it->v_names, it_result))
							{
								m_curr = it;
								break;
							}
						}
					}
				}
			}//end if (bneed)
		}//end for (auto it_result : vxunfei)

		ui.m_te_result->setText(result);
		ui.m_curr_status->setText(QString::fromLocal8Bit("识别结束"));
		ui.m_te_errinfo->setText(QString::fromLocal8Bit("无"));

		result = "";
		set_other_breast_info();
	}//end else
}

void record64::parse_listen_result(QString result)
{
	bool bneed = true;
	//部位和症状连着念的情况
	//比如 皮肤正常
	for (auto it : md_symptom_info)
	{
		if (compare_result(it->v_names, result))
		{
			set_breast_checked(it->index);

			if (it->pleft)
				it->pleft->setChecked(true);
			if (it->pright)
				it->pright->setChecked(true);
			bneed = false;
			break;
		}
	}

	//部位和症状分开念的情况
	//比如 皮肤  正常
	if (bneed)
	{
		if (m_curr == nullptr)
		{
			for (auto it : md_breast)
			{
				if (compare_result(it->v_names, result))
				{
					m_curr = it;
					break;
				}
			}
		}
		else
		{
			for (auto it : m_curr->vinfo)
			{
				if (compare_result(it->v_names, result))
				{
					set_breast_checked(it->index);

					if (it->pleft)
						it->pleft->setChecked(true);
					if (it->pright)
						it->pright->setChecked(true);

					m_curr = nullptr;
					break;
				}
			}
			//没有识别出来，设置默认值
			if (m_curr != nullptr)
			{
				set_breast_checked(m_curr->pdefault->index);

				if (m_curr->pdefault->pleft)
					m_curr->pdefault->pleft->setChecked(true);
				if (m_curr->pdefault->pright)
					m_curr->pdefault->pright->setChecked(true);

				m_curr = nullptr;

				//当没有识别出来 当前指向的具体内容时，再看一下是不是下一个指向的语音
				for (auto it : md_breast)
				{
					if (compare_result(it->v_names,result))
					{
						m_curr = it;
						break;
					}
				}
			}
		}
	}//end if (bneed)
}
//end private functions
