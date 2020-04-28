#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_record64.h"
#include "Config.h"
//#include "SliceIdGenerator.h"
//#include "Voice.h"
#include "record_dll.h"


#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>
#include <QFile>
#include <QtNetWork/QNetworkRequest>
#include <QtNetWork/QNetworkReply>
#include <QtNetWork/QNetworkAccessManager>
#include <QTimer>
#include <QLineEdit>

#include <vector>
#include <deque>
using namespace std;

#define INBUFSIZE    4096  
#define MP3BUFSIZE (int) (1.25 * INBUFSIZE) + 7200 

#define SIZE_AUDIO_FRAME (2)

/*struct WAVHEADER
{
	// RIFF 头
	char RiffName[4];
	unsigned long nRiffLength;
	char WavName[4];// 数据类型标识符
	char FmtName[4];// 格式块中的块头
	unsigned long nFmtLength;

	//格式块中的块数据
	unsigned short nAudioFormat;
	unsigned short nChannleNumber;
	unsigned long nSampleRate;
	unsigned long nBytesPerSecond;
	unsigned short nBytesPerSample;
	unsigned short nBitsPerSample;

	//数据块中的块头
	char    DATANAME[4];
	unsigned long   nDataLength;
};*/

struct rec_result
{
	QString qestion;
	QLineEdit *qledit;
};

//乳房部位状况信息 结构
typedef struct symptom
{
	QString sname;
	vector<QString> v_names;
	int index;
	QRadioButton* pleft;
	QRadioButton* pright;
}symptom_info;

//乳房部位信息 结构
typedef struct breast
{
	QString sname;
	vector<QString> v_names;
	vector<symptom_info*> vinfo;
	symptom* pdefault;
}breast_info;

//记录乳房某个部位 的情况时候已经被描述过
typedef struct realtime
{
	int index;
	bool bchecked;
	QRadioButton* pdefault;
}realtime_info;  

class record64 : public QMainWindow
{
	Q_OBJECT

public:
	record64(QWidget *parent = Q_NULLPTR);
	~record64();

	void closeEvent(QCloseEvent* e);

public slots:
	//void read_more();

	void set_path();
	void start_record();
	void end_record();
	void recognize_voice();
	void recognize_baidu();

	void select_baidu();
	void select_xunfei();

	void get_baidu_result();
	void get_xunfei_result();

	void listen_get_result();

	void start_listen();
	void stop_listen();

private:
	void out_errinfo(QString errinfo, int istep);
	void bak_voice_file(QString filename);

	int get_sample_rate();
	int get_channel_num();
	int get_mac_num();
	int get_speaker_num();
	int get_speak_mode();

	void RadioButton_Group();
	void init_info();
	void init_rutou_info();
	void init_pifu_info();
	void init_yiye_info();
	void init_xianti_info();
	void init_furu_info();
	void init_tengtong_info();
	void init_rufang_type_info();
	void init_start_end_info();

	void init_breast_rt_info();
	void set_breast_checked(int index);
	void set_other_breast_info();
	bool compare_result(vector<QString> &vnames,QString sresult);
	void read_config(QString config_name,QString name,vector<QString> &v_values);

	void parse_listen_result(QString result);

private:
	Ui::record64Class ui;

	QAudioInput* _audioInput; //录音对象
	QAudioInput* _audioInput2;

	QFile outFile;
	QFile outFile2;
	QByteArray voiceData;

	bool m_bstart_record;
	bool m_bend_record;
	bool m_bstart_listen;
	bool m_bwrite;                               //是否已经开始写入监听语音到文件中

	QString m_recognize_file;
	QString m_baidu_rec_file;
	QString m_record_path;                       //录音存放路径                    
	QString m_record_name;                       //录音文件名
	QString m_taskid;
	QString m_appid;
	QString m_secretKey;
	QString m_token;
	QString m_listen_basepath;                  //监听语音存放路径
	
	int m_imac_num;

	QTimer* m_timer;
	Config m_config;

	recognize_step m_step;
	int m_upload_count;                          //文件需要上传几次
	int m_realtime_count;                        //实时传送的次数

	vector<rec_result*> m_question;

	QLineEdit* m_ple;
	QString m_qscurr;

	int m_voice_sample_rate;
	int m_voice_bit_len;
	int m_voice_channel_num;
	int m_speaker_number;
	int m_speak_mode;

	int m_iprovider;      //1--baidu,2--xunfei

	bool m_baidu_return;
	int m_ibpos;       
	QString m_rec_result;

	vector<symptom_info*> v_breast_rt;
	vector<symptom_info*> v_breast_l_rt;
	vector<symptom_info*> v_breast_r_rt;
	vector<symptom_info*> v_breast_pf;
	vector<symptom_info*> v_breast_l_pf;
	vector<symptom_info*> v_breast_r_pf;
	vector<symptom_info*> v_breast_yy;
	vector<symptom_info*> v_breast_l_yy;
	vector<symptom_info*> v_breast_r_yy;
	vector<symptom_info*> v_breast_xt;
	vector<symptom_info*> v_breast_l_xt;
	vector<symptom_info*> v_breast_r_xt;
	vector<symptom_info*> v_breast_fr;
	vector<symptom_info*> v_breast_l_fr;
	vector<symptom_info*> v_breast_r_fr;
	vector<symptom_info*> v_breast_tt;
	vector<symptom_info*> v_breast_l_tt;
	vector<symptom_info*> v_breast_r_tt;
	vector<symptom_info*> v_breast_rflx;

	vector<realtime_info*> v_breast_realtime_info;

	vector<QString> v_start_info;
	vector<QString> v_end_info;

	deque<breast_info*> md_breast;
	deque<symptom_info*> md_symptom_info;
	breast_info* m_curr;

	QButtonGroup* ml_rt_group;
	QButtonGroup* ml_pf_group;
	QButtonGroup* ml_yy_group;
	QButtonGroup* ml_xt_group;
	QButtonGroup* ml_fr_group;
	QButtonGroup* ml_tt_group;

	QButtonGroup* mr_rt_group;
	QButtonGroup* mr_pf_group;
	QButtonGroup* mr_yy_group;
	QButtonGroup* mr_xt_group;
	QButtonGroup* mr_fr_group;
	QButtonGroup* mr_tt_group;
	QButtonGroup* mrflx_group;

	//begin xunfei
	//Voice* m_pvoice;
	int m_iepos;
	QString m_recognize_name;
	QFile* m_upload_file;
	QString m_recognize_basepath;
	//vector<QString> m_subvoice_path;
	//end xunfei


	//begin dll
	record_dll m_record_dll;
	QTimer *m_baidu_timer;
	QTimer *m_xunfei_timer;

	QTimer* m_listen_timer;
	//end dll
};
