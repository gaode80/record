#include "record64.h"

//乳头信息
void record64::init_rutou_info()
{
	//乳头
	symptom_info* prt_normal = new symptom_info();
	symptom_info* prt_up = new symptom_info();
	symptom_info* prt_aoxian = new symptom_info();
	symptom_info* prt_milan = new symptom_info();
	//prt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	//prt_normal->v_names.push_back(QString::fromLocal8Bit("整场"));
	//prt_normal->v_names.push_back(QString::fromLocal8Bit("正厂"));
	//prt_normal->v_names.push_back(QString::fromLocal8Bit("正昌"));
	//prt_normal->v_names.push_back(QString::fromLocal8Bit("正场"));
	read_config("/ini/rutou_config.ini","rutou_normal", prt_normal->v_names);
	prt_normal->pleft = ui.ml_rt_normal;
	prt_normal->pright = ui.mr_rt_normal;
	prt_normal->index = 1;
	//prt_up->v_names.push_back(QString::fromLocal8Bit("上抬"));
	//prt_up->v_names.push_back(QString::fromLocal8Bit("上台"));
	read_config("/ini/rutou_config.ini", "rutou_up", prt_up->v_names);
	prt_up->pleft = ui.ml_rt_up;
	prt_up->pright = ui.mr_rt_up;
	prt_up->index = 1;
	//prt_aoxian->v_names.push_back(QString::fromLocal8Bit("凹陷"));
	read_config("/ini/rutou_config.ini", "rutou_aoxian", prt_aoxian->v_names);
	prt_aoxian->pleft = ui.ml_rt_ax;
	prt_aoxian->pright = ui.mr_rt_ax;
	prt_aoxian->index = 1;
	//prt_milan->v_names.push_back(QString::fromLocal8Bit("糜烂"));
	read_config("/ini/rutou_config.ini", "rutou_milan", prt_milan->v_names);
	prt_milan->pleft = ui.ml_rt_ml;
	prt_milan->pright = ui.mr_rt_ml;
	prt_milan->index = 1;
	v_breast_rt.push_back(prt_normal);
	v_breast_rt.push_back(prt_up);
	v_breast_rt.push_back(prt_aoxian);
	v_breast_rt.push_back(prt_milan);
	breast_info* prutou = new breast_info();
	//prutou->v_names.push_back(QString::fromLocal8Bit("乳头"));
	read_config("/ini/rutou_config.ini", "rutou", prutou->v_names);
	prutou->vinfo = v_breast_rt;
	prutou->pdefault = prt_normal;
	md_breast.push_back(prutou);

	//左侧乳头
	symptom_info* pl_rt_normal = new symptom_info();
	symptom_info* pl_rt_up = new symptom_info();
	symptom_info* pl_rt_aoxian = new symptom_info();
	symptom_info* pl_rt_milan = new symptom_info();
	//pl_rt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/rutou_config.ini", "rutou_normal", pl_rt_normal->v_names);
	pl_rt_normal->pleft = ui.ml_rt_normal;
	pl_rt_normal->pright = nullptr;
	pl_rt_normal->index = 11;
	//pl_rt_up->v_names.push_back(QString::fromLocal8Bit("上抬"));
	//pl_rt_up->v_names.push_back(QString::fromLocal8Bit("上台"));
	read_config("/ini/rutou_config.ini", "rutou_up", pl_rt_up->v_names);
	pl_rt_up->pleft = ui.ml_rt_up;
	pl_rt_up->pright = nullptr;
	pl_rt_up->index = 11;
	//pl_rt_aoxian->v_names.push_back(QString::fromLocal8Bit("凹陷"));
	read_config("/ini/rutou_config.ini", "rutou_aoxian", pl_rt_aoxian->v_names);
	pl_rt_aoxian->pleft = ui.ml_rt_ax;
	pl_rt_aoxian->pright = nullptr;
	pl_rt_aoxian->index = 11;
	//pl_rt_milan->v_names.push_back(QString::fromLocal8Bit("糜烂"));
	read_config("/ini/rutou_config.ini", "rutou_milan", pl_rt_milan->v_names);
	pl_rt_milan->pleft = ui.ml_rt_ml;
	pl_rt_milan->pright = nullptr;
	pl_rt_milan->index = 11;
	v_breast_l_rt.push_back(pl_rt_normal);
	v_breast_l_rt.push_back(pl_rt_up);
	v_breast_l_rt.push_back(pl_rt_aoxian);
	v_breast_l_rt.push_back(pl_rt_milan);
	breast_info* pl_rutou = new breast_info();
	//pl_rutou->v_names.push_back(QString::fromLocal8Bit("左侧乳头"));
	read_config("/ini/rutou_config.ini", "l_rutou", pl_rutou->v_names);
	pl_rutou->vinfo = v_breast_rt;
	pl_rutou->pdefault = pl_rt_normal;
	md_breast.push_back(pl_rutou);

	//右侧乳头
	symptom_info* pr_rt_normal = new symptom_info();
	symptom_info* pr_rt_up = new symptom_info();
	symptom_info* pr_rt_aoxian = new symptom_info();
	symptom_info* pr_rt_milan = new symptom_info();
	//pr_rt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/rutou_config.ini", "rutou_normal", pr_rt_normal->v_names);
	pr_rt_normal->pleft = nullptr;
	pr_rt_normal->pright = ui.mr_rt_normal;
	pr_rt_normal->index = 12;
	//pr_rt_up->v_names.push_back(QString::fromLocal8Bit("上抬"));
	//pr_rt_up->v_names.push_back(QString::fromLocal8Bit("上台"));
	read_config("/ini/rutou_config.ini", "rutou_up", pr_rt_up->v_names);
	pr_rt_up->pleft = nullptr;
	pr_rt_up->pright = ui.mr_rt_up;
	pr_rt_up->index = 12;
	//pr_rt_aoxian->v_names.push_back(QString::fromLocal8Bit("凹陷"));
	read_config("/ini/rutou_config.ini", "rutou_aoxian", pr_rt_aoxian->v_names);
	pr_rt_aoxian->pleft = nullptr;
	pr_rt_aoxian->pright = ui.mr_rt_ax;
	pr_rt_aoxian->index = 12;
	//pr_rt_milan->v_names.push_back(QString::fromLocal8Bit("糜烂"));
	read_config("/ini/rutou_config.ini", "rutou_milan", pr_rt_milan->v_names);
	pr_rt_milan->pleft = nullptr;
	pr_rt_milan->pright = ui.mr_rt_ml;
	pr_rt_milan->index = 12;
	v_breast_r_rt.push_back(pr_rt_normal);
	v_breast_r_rt.push_back(pr_rt_up);
	v_breast_r_rt.push_back(pr_rt_aoxian);
	v_breast_r_rt.push_back(pr_rt_milan);
	breast_info* pr_rutou = new breast_info();
	//pr_rutou->v_names.push_back(QString::fromLocal8Bit("右侧乳头"));
	read_config("/ini/rutou_config.ini", "r_rutou", pl_rutou->v_names);
	pr_rutou->vinfo = v_breast_rt;
	pr_rutou->pdefault = pr_rt_normal;
	md_breast.push_back(pr_rutou);

	//乳头单项
	symptom_info* prt_normal_s = new symptom_info();
	symptom_info* prt_ax_s = new symptom_info();
	symptom_info* prt_up_s = new symptom_info();
	symptom_info* prt_ml_s = new symptom_info();
	//prt_normal_s->v_names.push_back(QString::fromLocal8Bit("乳头正常"));
	read_config("/ini/rutou_config.ini", "rutou_all_normal", prt_normal_s->v_names);
	prt_normal_s->pleft = ui.ml_rt_normal;
	prt_normal_s->pright = ui.mr_rt_normal;
	prt_normal_s->index = 1;
	//prt_up_s->v_names.push_back(QString::fromLocal8Bit("乳头上抬"));
	//prt_up_s->v_names.push_back(QString::fromLocal8Bit("乳头上台"));
	//prt_up_s->v_names.push_back(QString::fromLocal8Bit("乳头上牌"));
	//prt_up_s->v_names.push_back(QString::fromLocal8Bit("骨头上台"));
	read_config("/ini/rutou_config.ini", "rutou_all_up", prt_up_s->v_names);
	prt_up_s->pleft = ui.ml_rt_up;
	prt_up_s->pright = ui.mr_rt_up;
	prt_up_s->index = 1;
	//prt_ax_s->v_names.push_back(QString::fromLocal8Bit("乳头凹陷"));
	//prt_ax_s->v_names.push_back(QString::fromLocal8Bit("骨头凹陷")); 
	read_config("/ini/rutou_config.ini", "rutou_all_aoxian", prt_ax_s->v_names);
	prt_ax_s->pleft = ui.ml_rt_ax;
	prt_ax_s->pright = ui.mr_rt_ax;
	prt_ax_s->index = 1;
	//prt_ml_s->v_names.push_back(QString::fromLocal8Bit("乳头糜烂"));
	//prt_ml_s->v_names.push_back(QString::fromLocal8Bit("路透迷了")); 
	read_config("/ini/rutou_config.ini", "rutou_all_milan", prt_ml_s->v_names);
	prt_ml_s->pleft = ui.ml_rt_ml;
	prt_ml_s->pright = ui.mr_rt_ml;
	prt_ml_s->index = 1;
	md_symptom_info.push_back(prt_normal_s);
	md_symptom_info.push_back(prt_up_s);
	md_symptom_info.push_back(prt_ax_s);
	md_symptom_info.push_back(prt_ml_s);

	//左侧乳头单项
	symptom_info* pl_rt_normal_s = new symptom_info();
	symptom_info* pl_rt_ax_s = new symptom_info();
	symptom_info* pl_rt_up_s = new symptom_info();
	symptom_info* pl_rt_ml_s = new symptom_info();
	//pl_rt_normal_s->v_names.push_back(QString::fromLocal8Bit("左侧乳头正常"));
	read_config("/ini/rutou_config.ini", "l_rutou_normal", pl_rt_normal_s->v_names);
	pl_rt_normal_s->pleft = ui.ml_rt_normal;
	pl_rt_normal_s->pright = nullptr;
	pl_rt_normal_s->index = 11;
	//pl_rt_up_s->v_names.push_back(QString::fromLocal8Bit("左侧乳头上抬"));
	//pl_rt_up_s->v_names.push_back(QString::fromLocal8Bit("左侧乳头上台"));
	read_config("/ini/rutou_config.ini", "l_rutou_up", pl_rt_up_s->v_names);
	pl_rt_up_s->pleft = ui.ml_rt_up;
	pl_rt_up_s->pright = nullptr;
	pl_rt_up_s->index = 11;
	//pl_rt_ax_s->v_names.push_back(QString::fromLocal8Bit("左侧乳头凹陷"));
	read_config("/ini/rutou_config.ini", "l_rutou_aoxian", pl_rt_ax_s->v_names);
	pl_rt_ax_s->pleft = ui.ml_rt_ax;
	pl_rt_ax_s->pright = nullptr;
	pl_rt_ax_s->index = 11;
	//pl_rt_ml_s->v_names.push_back(QString::fromLocal8Bit("左侧乳头糜烂"));
	read_config("/ini/rutou_config.ini", "l_rutou_milan", pl_rt_ml_s->v_names);
	pl_rt_ml_s->pleft = ui.ml_rt_ml;
	pl_rt_ml_s->pright = nullptr;
	pl_rt_ml_s->index = 11;
	md_symptom_info.push_back(pl_rt_normal_s);
	md_symptom_info.push_back(pl_rt_up_s);
	md_symptom_info.push_back(pl_rt_ax_s);
	md_symptom_info.push_back(pl_rt_ml_s);

	//右侧乳头单项
	symptom_info* pr_rt_normal_s = new symptom_info();
	symptom_info* pr_rt_ax_s = new symptom_info();
	symptom_info* pr_rt_up_s = new symptom_info();
	symptom_info* pr_rt_ml_s = new symptom_info();
	//pr_rt_normal_s->v_names.push_back(QString::fromLocal8Bit("右侧乳头正常"));
	read_config("/ini/rutou_config.ini", "r_rutou_normal", pr_rt_normal_s->v_names);
	pr_rt_normal_s->pleft = nullptr;
	pr_rt_normal_s->pright = ui.mr_rt_normal;
	pr_rt_normal_s->index = 12;
	//pr_rt_up_s->v_names.push_back(QString::fromLocal8Bit("右侧乳头上抬"));
	//pr_rt_up_s->v_names.push_back(QString::fromLocal8Bit("右侧乳头上台"));
	read_config("/ini/rutou_config.ini", "r_rutou_up", pr_rt_up_s->v_names);
	pr_rt_up_s->pleft = nullptr;
	pr_rt_up_s->pright = ui.mr_rt_up;
	pr_rt_up_s->index = 12;
	//pr_rt_ax_s->v_names.push_back(QString::fromLocal8Bit("右侧乳头凹陷"));
	read_config("/ini/rutou_config.ini", "r_rutou_aoxian", pr_rt_ax_s->v_names);
	pr_rt_ax_s->pleft = nullptr;
	pr_rt_ax_s->pright = ui.mr_rt_ax;
	pr_rt_ax_s->index = 12;
	//pr_rt_ml_s->v_names.push_back(QString::fromLocal8Bit("右侧乳头糜烂"));
	read_config("/ini/rutou_config.ini", "r_rutou_milan", pr_rt_ml_s->v_names);
	pr_rt_ml_s->pleft = nullptr;
	pr_rt_ml_s->pright = ui.mr_rt_ml;
	pr_rt_ml_s->index = 12;
	md_symptom_info.push_back(pr_rt_normal_s);
	md_symptom_info.push_back(pr_rt_up_s);
	md_symptom_info.push_back(pr_rt_ax_s);
	md_symptom_info.push_back(pr_rt_ml_s);
}

//皮肤信息
void record64::init_pifu_info()
{
	//皮肤
	symptom_info* ppf_normal = new symptom_info();
	symptom_info* ppf_jwz = new symptom_info();
	symptom_info* ppf_jpy = new symptom_info();
	symptom_info* ppf_jy = new symptom_info();
	//ppf_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/pifu_config.ini", "pifu_normal", ppf_normal->v_names);
	ppf_normal->pleft = ui.ml_pf_normal;
	ppf_normal->pright = ui.mr_pf_normal;
	ppf_normal->index = 2;
	//ppf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝征"));
	//ppf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝症"));
	read_config("/ini/pifu_config.ini", "pifu_jwz", ppf_jwz->v_names);
	ppf_jwz->pleft = ui.ml_pf_jwz;
	ppf_jwz->pright = ui.mr_pf_jwz;
	ppf_jwz->index = 2;
	//ppf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮样"));
	//ppf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮一样"));
	read_config("/ini/pifu_config.ini", "pifu_jpy", ppf_jpy->v_names);
	ppf_jpy->pleft = ui.ml_pf_jpy;
	ppf_jpy->pright = ui.mr_pf_jpy;
	ppf_jpy->index = 2;
	//ppf_jy->v_names.push_back(QString::fromLocal8Bit("兼有"));
	//ppf_jy->v_names.push_back(QString::fromLocal8Bit("先由"));
	read_config("/ini/pifu_config.ini", "pifu_jianyou", ppf_jy->v_names);
	ppf_jy->pleft = ui.ml_pf_jy;
	ppf_jy->pright = ui.mr_pf_jy;
	ppf_jy->index = 2;
	v_breast_pf.push_back(ppf_normal);
	v_breast_pf.push_back(ppf_jwz);
	v_breast_pf.push_back(ppf_jpy);
	v_breast_pf.push_back(ppf_jy);
	breast_info* ppf = new breast_info();
	//ppf->v_names.push_back(QString::fromLocal8Bit("皮肤"));
	read_config("/ini/pifu_config.ini", "pifu", ppf->v_names);
	ppf->vinfo = v_breast_pf;
	ppf->pdefault = ppf_normal;
	md_breast.push_back(ppf);

	//左侧皮肤
	symptom_info* pl_pf_normal = new symptom_info();
	symptom_info* pl_pf_jwz = new symptom_info();
	symptom_info* pl_pf_jpy = new symptom_info();
	symptom_info* pl_pf_jy = new symptom_info();
	//pl_pf_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/pifu_config.ini", "pifu_normal", pl_pf_normal->v_names);
	pl_pf_normal->pleft = ui.ml_pf_normal;
	pl_pf_normal->pright = nullptr;
	pl_pf_normal->index = 21;
	//pl_pf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝征"));
	//pl_pf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝症"));
	read_config("/ini/pifu_config.ini", "pifu_jwz", pl_pf_jwz->v_names);
	pl_pf_jwz->pleft = ui.ml_pf_jwz;
	pl_pf_jwz->pright = nullptr;
	pl_pf_jwz->index = 21;
	//pl_pf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮样"));
	//pl_pf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮一样"));
	read_config("/ini/pifu_config.ini", "pifu_jpy", pl_pf_jpy->v_names);
	pl_pf_jpy->pleft = ui.ml_pf_jpy;
	pl_pf_jpy->pright = nullptr;
	pl_pf_jpy->index = 21;
	//pl_pf_jy->v_names.push_back(QString::fromLocal8Bit("兼有"));
	//pl_pf_jy->v_names.push_back(QString::fromLocal8Bit("先由"));
	read_config("/ini/pifu_config.ini", "pifu_jianyou", pl_pf_jy->v_names);
	pl_pf_jy->pleft = ui.ml_pf_jy;
	pl_pf_jy->pright = nullptr;
	pl_pf_jy->index = 21;
	v_breast_l_pf.push_back(pl_pf_normal);
	v_breast_l_pf.push_back(pl_pf_jwz);
	v_breast_l_pf.push_back(pl_pf_jpy);
	v_breast_l_pf.push_back(pl_pf_jy);
	breast_info* pl_pf = new breast_info();
	//pl_pf->v_names.push_back(QString::fromLocal8Bit("左侧皮肤"));
	read_config("/ini/pifu_config.ini", "l_pifu", pl_pf->v_names);
	pl_pf->vinfo = v_breast_pf;
	pl_pf->pdefault = pl_pf_normal;
	md_breast.push_back(pl_pf);

	//右侧皮肤
	symptom_info* pr_pf_normal = new symptom_info();
	symptom_info* pr_pf_jwz = new symptom_info();
	symptom_info* pr_pf_jpy = new symptom_info();
	symptom_info* pr_pf_jy = new symptom_info();
	//pr_pf_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/pifu_config.ini", "pifu_normal", pr_pf_normal->v_names);
	pr_pf_normal->pleft = nullptr;
	pr_pf_normal->pright = ui.mr_pf_normal;
	pr_pf_normal->index = 22;
	//pr_pf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝征"));
	//pr_pf_jwz->v_names.push_back(QString::fromLocal8Bit("酒窝症"));
	read_config("/ini/pifu_config.ini", "pifu_jwz", pr_pf_jwz->v_names);
	pr_pf_jwz->pleft = nullptr;
	pr_pf_jwz->pright = ui.mr_pf_jwz;
	pr_pf_jwz->index = 22;
	//pr_pf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮样"));
	//pr_pf_jpy->v_names.push_back(QString::fromLocal8Bit("橘皮一样"));
	read_config("/ini/pifu_config.ini", "pifu_jpy", pr_pf_jpy->v_names);
	pr_pf_jpy->pleft = nullptr;
	pr_pf_jpy->pright = ui.mr_pf_jpy;
	pr_pf_jpy->index = 22;
	//pr_pf_jy->v_names.push_back(QString::fromLocal8Bit("兼有"));
	//pr_pf_jy->v_names.push_back(QString::fromLocal8Bit("先由"));
	read_config("/ini/pifu_config.ini", "pifu_jianyou", pr_pf_jy->v_names);
	pr_pf_jy->pleft = nullptr;
	pr_pf_jy->pright = ui.mr_pf_jy;
	pr_pf_jy->index = 22;
	v_breast_r_pf.push_back(pr_pf_normal);
	v_breast_r_pf.push_back(pr_pf_jwz);
	v_breast_r_pf.push_back(pr_pf_jpy);
	v_breast_r_pf.push_back(pr_pf_jy);
	breast_info* pr_pf = new breast_info();
	//pr_pf->v_names.push_back(QString::fromLocal8Bit("右侧皮肤"));
	read_config("/ini/pifu_config.ini", "r_pifu", pr_pf->v_names);
	pr_pf->vinfo = v_breast_pf;
	pr_pf->pdefault = pr_pf_normal;
	md_breast.push_back(pr_pf);

	//皮肤单项
	symptom_info* ppf_normal_s = new symptom_info();
	symptom_info* ppf_jwz_s = new symptom_info();
	symptom_info* ppf_jpy_s = new symptom_info();
	symptom_info* ppf_jy_s = new symptom_info();
	//ppf_normal_s->v_names.push_back(QString::fromLocal8Bit("皮肤正常"));
	read_config("/ini/pifu_config.ini", "pifu_all_normal", ppf_normal_s->v_names);
	ppf_normal_s->pleft = ui.ml_pf_normal;
	ppf_normal_s->pright = ui.mr_pf_normal;
	ppf_normal_s->index = 2;
	//ppf_jwz_s->v_names.push_back(QString::fromLocal8Bit("皮肤酒窝征")); 
	//ppf_jwz_s->v_names.push_back(QString::fromLocal8Bit("皮肤酒窝整")); 
	read_config("/ini/pifu_config.ini", "pifu_all_jwz", ppf_jwz_s->v_names);
	ppf_jwz_s->pleft = ui.ml_pf_jwz;
	ppf_jwz_s->pright = ui.mr_pf_jwz;
	ppf_jwz_s->index = 2;
	//ppf_jpy_s->v_names.push_back(QString::fromLocal8Bit("皮肤橘皮样"));
	read_config("/ini/pifu_config.ini", "pifu_all_jpy", ppf_jpy_s->v_names);
	ppf_jpy_s->pleft = ui.ml_pf_jpy;
	ppf_jpy_s->pright = ui.mr_pf_jpy;
	ppf_jpy_s->index = 2;
	//ppf_jy_s->v_names.push_back(QString::fromLocal8Bit("皮肤兼有"));
	read_config("/ini/pifu_config.ini", "pifu_all_jianyou", ppf_jy_s->v_names);
	ppf_jy_s->pleft = ui.ml_pf_jy;
	ppf_jy_s->pright = ui.mr_pf_jy;
	ppf_jy_s->index = 2;
	md_symptom_info.push_back(ppf_normal_s);
	md_symptom_info.push_back(ppf_jwz_s);
	md_symptom_info.push_back(ppf_jpy_s);
	md_symptom_info.push_back(ppf_jy_s);

	//左侧皮肤单项
	symptom_info* pl_pf_normal_s = new symptom_info();
	symptom_info* pl_pf_jwz_s = new symptom_info();
	symptom_info* pl_pf_jpy_s = new symptom_info();
	symptom_info* pl_pf_jy_s = new symptom_info();
	//pl_pf_normal_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤正常"));
	read_config("/ini/pifu_config.ini", "l_pifu_normal", pl_pf_normal_s->v_names);
	pl_pf_normal_s->pleft = ui.ml_pf_normal;
	pl_pf_normal_s->pright = nullptr;
	pl_pf_normal_s->index = 21;
	//pl_pf_jwz_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤酒窝征"));
	//pl_pf_jwz_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤酒窝症"));
	read_config("/ini/pifu_config.ini", "l_pifu_jwz", pl_pf_jwz_s->v_names);
	pl_pf_jwz_s->pleft = ui.ml_pf_jwz;
	pl_pf_jwz_s->pright = nullptr;
	pl_pf_jwz_s->index = 21;
	//pl_pf_jpy_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤橘皮样"));
	//pl_pf_jpy_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤橘皮一样"));
	read_config("/ini/pifu_config.ini", "l_pifu_jpy", pl_pf_jpy_s->v_names);
	pl_pf_jpy_s->pleft = ui.ml_pf_jpy;
	pl_pf_jpy_s->pright = nullptr;
	pl_pf_jpy_s->index = 21;
	//pl_pf_jy_s->v_names.push_back(QString::fromLocal8Bit("左侧皮肤兼有"));
	read_config("/ini/pifu_config.ini", "l_pifu_jianyou", pl_pf_jy_s->v_names);
	pl_pf_jy_s->pleft = ui.ml_pf_jy;
	pl_pf_jy_s->pright = nullptr;
	pl_pf_jy_s->index = 21;
	md_symptom_info.push_back(pl_pf_normal_s);
	md_symptom_info.push_back(pl_pf_jwz_s);
	md_symptom_info.push_back(pl_pf_jpy_s);
	md_symptom_info.push_back(pl_pf_jy_s);

	//右侧皮肤单项
	symptom_info* pr_pf_normal_s = new symptom_info();
	symptom_info* pr_pf_jwz_s = new symptom_info();
	symptom_info* pr_pf_jpy_s = new symptom_info();
	symptom_info* pr_pf_jy_s = new symptom_info();
	//pr_pf_normal_s->v_names.push_back(QString::fromLocal8Bit("右侧皮肤正常"));
	read_config("/ini/pifu_config.ini", "r_pifu_normal", pr_pf_normal_s->v_names);
	pr_pf_normal_s->pleft = nullptr;
	pr_pf_normal_s->pright = ui.mr_pf_normal;
	pr_pf_normal_s->index = 22;
	//pr_pf_jwz_s->v_names.push_back(QString::fromLocal8Bit("右侧皮肤酒窝征"));
	read_config("/ini/pifu_config.ini", "r_pifu_jwz", pr_pf_jwz_s->v_names);
	pr_pf_jwz_s->pleft = nullptr;
	pr_pf_jwz_s->pright = ui.mr_pf_jwz;
	pr_pf_jwz_s->index = 22;
	//pr_pf_jpy_s->v_names.push_back(QString::fromLocal8Bit("右侧皮肤橘皮样"));
	read_config("/ini/pifu_config.ini", "r_pifu_jpy", pr_pf_jpy_s->v_names);
	pr_pf_jpy_s->pleft = nullptr;
	pr_pf_jpy_s->pright = ui.mr_pf_jpy;
	pr_pf_jpy_s->index = 22;
	//pr_pf_jy_s->v_names.push_back(QString::fromLocal8Bit("右侧皮肤兼有"));
	read_config("/ini/pifu_config.ini", "r_pifu_jianyou", pr_pf_jy_s->v_names);
	pr_pf_jy_s->pleft = nullptr;
	pr_pf_jy_s->pright = ui.mr_pf_jy;
	pr_pf_jy_s->index = 22;
	md_symptom_info.push_back(pr_pf_normal_s);
	md_symptom_info.push_back(pr_pf_jwz_s);
	md_symptom_info.push_back(pr_pf_jpy_s);
	md_symptom_info.push_back(pr_pf_jy_s);
}

//溢液信息
void record64::init_yiye_info()
{
	//溢液
	symptom_info* pyy_no = new symptom_info();
	symptom_info* pyy_single = new symptom_info();
	symptom_info* pyy_multi = new symptom_info();
	symptom_info* pyy_xx = new symptom_info();
	symptom_info* pyy_yellow = new symptom_info();
	symptom_info* pyy_ry = new symptom_info();
	symptom_info* pyy_qsy = new symptom_info();
	//pyy_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pyy_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/yiye_config.ini", "yiye_no", pyy_no->v_names);
	pyy_no->pleft = ui.ml_yy_no;
	pyy_no->pright = ui.mr_yy_no;
	pyy_no->index = 3;
	//pyy_single->v_names.push_back(QString::fromLocal8Bit("单管"));
	read_config("/ini/yiye_config.ini", "yiye_danguan", pyy_single->v_names);
	pyy_single->pleft = ui.ml_yy_single;
	pyy_single->pright = ui.mr_yy_single;
	pyy_single->index = 3;
	//pyy_multi->v_names.push_back(QString::fromLocal8Bit("多管"));
	read_config("/ini/yiye_config.ini", "yiye_duoguan", pyy_multi->v_names);
	pyy_multi->pleft = ui.ml_yy_multi;
	pyy_multi->pright = ui.mr_yy_multi;
	pyy_multi->index = 3;
	//pyy_xx->v_names.push_back(QString::fromLocal8Bit("血性"));
	//pyy_xx->v_names.push_back(QString::fromLocal8Bit("血型"));
	//pyy_xx->v_names.push_back(QString::fromLocal8Bit("血腥"));
	read_config("/ini/yiye_config.ini", "yiye_xuexing", pyy_xx->v_names);
	pyy_xx->pleft = ui.ml_yy_xx;
	pyy_xx->pright = ui.mr_yy_xx;
	pyy_xx->index = 3;
	//pyy_yellow->v_names.push_back(QString::fromLocal8Bit("黄色"));
	read_config("/ini/yiye_config.ini", "yiye_yellow", pyy_yellow->v_names);
	pyy_yellow->pleft = ui.ml_yy_yellow;
	pyy_yellow->pright = ui.mr_yy_yellow;
	pyy_yellow->index = 3;
	//pyy_ry->v_names.push_back(QString::fromLocal8Bit("乳样"));
	read_config("/ini/yiye_config.ini", "yiye_ruyang", pyy_ry->v_names);
	pyy_ry->pleft = ui.ml_yy_ry;
	pyy_ry->pright = ui.mr_yy_ry;
	pyy_ry->index = 3;
	//pyy_qsy->v_names.push_back(QString::fromLocal8Bit("清水样"));
	read_config("/ini/yiye_config.ini", "yiye_qsy", pyy_qsy->v_names);
	pyy_qsy->pleft = ui.ml_yy_qsy;
	pyy_qsy->pright = ui.mr_yy_qsy;
	pyy_qsy->index = 3;
	v_breast_yy.push_back(pyy_no);
	v_breast_yy.push_back(pyy_single);
	v_breast_yy.push_back(pyy_multi);
	v_breast_yy.push_back(pyy_xx);
	v_breast_yy.push_back(pyy_yellow);
	v_breast_yy.push_back(pyy_ry);
	v_breast_yy.push_back(pyy_qsy);
	breast_info* pyy = new breast_info();
	//pyy->v_names.push_back(QString::fromLocal8Bit("溢液"));
	//pyy->v_names.push_back(QString::fromLocal8Bit("一页"));
	//pyy->v_names.push_back(QString::fromLocal8Bit("一夜"));
	//pyy->v_names.push_back(QString::fromLocal8Bit("一叶"));
	//pyy->v_names.push_back(QString::fromLocal8Bit("异业"));
	//pyy->v_names.push_back(QString::fromLocal8Bit("第1页")); 
	read_config("/ini/yiye_config.ini", "yiye", pyy->v_names);
	pyy->vinfo = v_breast_yy;
	pyy->pdefault = pyy_no;
	md_breast.push_back(pyy);

	//左侧溢液
	symptom_info* pl_yy_no = new symptom_info();
	symptom_info* pl_yy_single = new symptom_info();
	symptom_info* pl_yy_multi = new symptom_info();
	symptom_info* pl_yy_xx = new symptom_info();
	symptom_info* pl_yy_yellow = new symptom_info();
	symptom_info* pl_yy_ry = new symptom_info();
	symptom_info* pl_yy_qsy = new symptom_info();
	//pl_yy_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pl_yy_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/yiye_config.ini", "yiye_no", pl_yy_no->v_names);
	pl_yy_no->pleft = ui.ml_yy_no;
	pl_yy_no->pright = nullptr;
	pl_yy_no->index = 31;
	//pl_yy_single->v_names.push_back(QString::fromLocal8Bit("单管"));
	read_config("/ini/yiye_config.ini", "yiye_danguan", pl_yy_single->v_names);
	pl_yy_single->pleft = ui.ml_yy_single;
	pl_yy_single->pright = nullptr;
	pl_yy_single->index = 31;
	//pl_yy_multi->v_names.push_back(QString::fromLocal8Bit("多管"));
	read_config("/ini/yiye_config.ini", "yiye_duoguan", pl_yy_multi->v_names);
	pl_yy_multi->pleft = ui.ml_yy_multi;
	pl_yy_multi->pright = nullptr;
	pl_yy_multi->index = 31;
	//pl_yy_xx->v_names.push_back(QString::fromLocal8Bit("血性"));
	//pl_yy_xx->v_names.push_back(QString::fromLocal8Bit("血型"));
	//pl_yy_xx->v_names.push_back(QString::fromLocal8Bit("血腥"));
	//pl_yy_xx->v_names.push_back(QString::fromLocal8Bit("觉性"));
	read_config("/ini/yiye_config.ini", "yiye_xuexing", pl_yy_xx->v_names);
	pl_yy_xx->pleft = ui.ml_yy_xx;
	pl_yy_xx->pright = nullptr;
	pl_yy_xx->index = 31;
	//pl_yy_yellow->v_names.push_back(QString::fromLocal8Bit("黄色"));
	read_config("/ini/yiye_config.ini", "yiye_yellow", pl_yy_yellow->v_names);
	pl_yy_yellow->pleft = ui.ml_yy_yellow;
	pl_yy_yellow->pright = nullptr;
	pl_yy_yellow->index = 31;
	//pl_yy_ry->v_names.push_back(QString::fromLocal8Bit("乳样"));
	read_config("/ini/yiye_config.ini", "yiye_ruyang", pl_yy_ry->v_names);
	pl_yy_ry->pleft = ui.ml_yy_ry;
	pl_yy_ry->pright = nullptr;
	pl_yy_ry->index = 31;
	//pl_yy_qsy->v_names.push_back(QString::fromLocal8Bit("清水样"));
	//pl_yy_qsy->v_names.push_back(QString::fromLocal8Bit("清水一样"));
	read_config("/ini/yiye_config.ini", "yiye_qsy", pl_yy_qsy->v_names);
	pl_yy_qsy->pleft = ui.ml_yy_qsy;
	pl_yy_qsy->pright = nullptr;
	pl_yy_qsy->index = 31;
	v_breast_l_yy.push_back(pl_yy_no);
	v_breast_l_yy.push_back(pl_yy_single);
	v_breast_l_yy.push_back(pl_yy_multi);
	v_breast_l_yy.push_back(pl_yy_xx);
	v_breast_l_yy.push_back(pl_yy_yellow);
	v_breast_l_yy.push_back(pl_yy_ry);
	v_breast_l_yy.push_back(pl_yy_qsy);
	breast_info* pl_yy = new breast_info();
	//pl_yy->v_names.push_back(QString::fromLocal8Bit("左侧溢液"));
	//pl_yy->v_names.push_back(QString::fromLocal8Bit("左侧一页"));
	read_config("/ini/yiye_config.ini", "l_yiye", pl_yy->v_names);
	pl_yy->vinfo = v_breast_l_yy;
	pl_yy->pdefault = pl_yy_no;
	md_breast.push_back(pl_yy);

	//右侧溢液
	symptom_info* pr_yy_no = new symptom_info();
	symptom_info* pr_yy_single = new symptom_info();
	symptom_info* pr_yy_multi = new symptom_info();
	symptom_info* pr_yy_xx = new symptom_info();
	symptom_info* pr_yy_yellow = new symptom_info();
	symptom_info* pr_yy_ry = new symptom_info();
	symptom_info* pr_yy_qsy = new symptom_info();
	//pr_yy_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pr_yy_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/yiye_config.ini", "yiye_no", pr_yy_no->v_names);
	pr_yy_no->pleft = nullptr;
	pr_yy_no->pright = ui.mr_yy_no;
	pr_yy_no->index = 32;
	//pr_yy_single->v_names.push_back(QString::fromLocal8Bit("单管"));
	read_config("/ini/yiye_config.ini", "yiye_danguan", pr_yy_single->v_names);
	pr_yy_single->pleft = nullptr;
	pr_yy_single->pright = ui.mr_yy_single;
	pr_yy_single->index = 32;
	//pr_yy_multi->v_names.push_back(QString::fromLocal8Bit("多管"));
	read_config("/ini/yiye_config.ini", "yiye_duoguan", pr_yy_multi->v_names);
	pr_yy_multi->pleft = nullptr;
	pr_yy_multi->pright = ui.mr_yy_multi;
	pr_yy_multi->index = 32;
	//pr_yy_xx->v_names.push_back(QString::fromLocal8Bit("血性"));
	read_config("/ini/yiye_config.ini", "yiye_xuexing", pr_yy_xx->v_names);
	pr_yy_xx->pleft = nullptr;
	pr_yy_xx->pright = ui.mr_yy_xx;
	pr_yy_xx->index = 32;
	//pr_yy_yellow->v_names.push_back(QString::fromLocal8Bit("黄色"));
	read_config("/ini/yiye_config.ini", "yiye_yellow", pr_yy_yellow->v_names);
	pr_yy_yellow->pleft = nullptr;
	pr_yy_yellow->pright = ui.mr_yy_yellow;
	pr_yy_yellow->index = 32;
	//pr_yy_ry->v_names.push_back(QString::fromLocal8Bit("乳样"));
	read_config("/ini/yiye_config.ini", "yiye_ruyang", pr_yy_ry->v_names);
	pr_yy_ry->pleft = nullptr;
	pr_yy_ry->pright = ui.mr_yy_ry;
	pr_yy_ry->index = 32;
	//pr_yy_qsy->v_names.push_back(QString::fromLocal8Bit("清水样"));
	read_config("/ini/yiye_config.ini", "yiye_qsy", pr_yy_qsy->v_names);
	pr_yy_qsy->pleft = nullptr;
	pr_yy_qsy->pright = ui.mr_yy_qsy;
	pr_yy_qsy->index = 32;
	v_breast_r_yy.push_back(pr_yy_no);
	v_breast_r_yy.push_back(pr_yy_single);
	v_breast_r_yy.push_back(pr_yy_multi);
	v_breast_r_yy.push_back(pr_yy_xx);
	v_breast_r_yy.push_back(pr_yy_yellow);
	v_breast_r_yy.push_back(pr_yy_ry);
	v_breast_r_yy.push_back(pr_yy_qsy);
	breast_info* pr_yy = new breast_info();
	//pr_yy->v_names.push_back(QString::fromLocal8Bit("右侧溢液"));
	//pr_yy->v_names.push_back(QString::fromLocal8Bit("右侧异业"));
	//pr_yy->v_names.push_back(QString::fromLocal8Bit("右侧一页"));
	//pr_yy->v_names.push_back(QString::fromLocal8Bit("右侧一叶"));
	read_config("/ini/yiye_config.ini", "r_yiye", pr_yy->v_names);
	pr_yy->vinfo = v_breast_l_yy;
	pr_yy->pdefault = pr_yy_no;
	md_breast.push_back(pr_yy);

	//溢液单项
	symptom_info* pyy_no_s = new symptom_info();
	symptom_info* pyy_single_s = new symptom_info();
	symptom_info* pyy_multi_s = new symptom_info();
	symptom_info* pyy_xx_s = new symptom_info();
	symptom_info* pyy_yellow_s = new symptom_info();
	symptom_info* pyy_ry_s = new symptom_info();
	symptom_info* pyy_qsy_s = new symptom_info();
	//pyy_no_s->v_names.push_back(QString::fromLocal8Bit("溢液无"));
	read_config("/ini/yiye_config.ini", "yiye_all_no", pyy_no_s->v_names);
	pyy_no_s->pleft = ui.ml_yy_no;
	pyy_no_s->pright = ui.mr_yy_no;
	pyy_no_s->index = 3;
	//pyy_single_s->v_names.push_back(QString::fromLocal8Bit("溢液单管"));
	//pyy_single_s->v_names.push_back(QString::fromLocal8Bit("一夜单管")); 
	read_config("/ini/yiye_config.ini", "yiye_all_danguan", pyy_single_s->v_names);
	pyy_single_s->pleft = ui.ml_yy_single;
	pyy_single_s->pright = ui.mr_yy_single;
	pyy_single_s->index = 3;
	//pyy_multi_s->v_names.push_back(QString::fromLocal8Bit("溢液多管")); 
	//pyy_multi_s->v_names.push_back(QString::fromLocal8Bit("一也多管")); 
	//pyy_multi_s->v_names.push_back(QString::fromLocal8Bit("一页多寡"));
	//pyy_multi_s->v_names.push_back(QString::fromLocal8Bit("一夜多管")); 
	read_config("/ini/yiye_config.ini", "yiye_all_duoguan", pyy_multi_s->v_names);
	pyy_multi_s->pleft = ui.ml_yy_multi;
	pyy_multi_s->pright = ui.mr_yy_multi;
	pyy_multi_s->index = 3;
	//pyy_xx_s->v_names.push_back(QString::fromLocal8Bit("溢液血性")); 
	//pyy_xx_s->v_names.push_back(QString::fromLocal8Bit("一夜血性")); 
	read_config("/ini/yiye_config.ini", "yiye_all_xuexing", pyy_xx_s->v_names);
	pyy_xx_s->pleft = ui.ml_yy_xx;
	pyy_xx_s->pright = ui.mr_yy_xx;
	pyy_xx_s->index = 3;
	//pyy_yellow_s->v_names.push_back(QString::fromLocal8Bit("溢液黄色"));
	read_config("/ini/yiye_config.ini", "yiye_all_yellow", pyy_yellow_s->v_names);
	pyy_yellow_s->pleft = ui.ml_yy_yellow;
	pyy_yellow_s->pright = ui.mr_yy_yellow;
	pyy_yellow_s->index = 3;
	//pyy_ry_s->v_names.push_back(QString::fromLocal8Bit("溢液乳样"));
	read_config("/ini/yiye_config.ini", "yiye_all_ruyang", pyy_ry_s->v_names);
	pyy_ry_s->pleft = ui.ml_yy_ry;
	pyy_ry_s->pright = ui.mr_yy_ry;
	pyy_ry_s->index = 3;
	//pyy_qsy_s->v_names.push_back(QString::fromLocal8Bit("溢液清水样"));
	read_config("/ini/yiye_config.ini", "yiye_all_qsy", pyy_qsy_s->v_names);
	pyy_qsy_s->pleft = ui.ml_yy_qsy;
	pyy_qsy_s->pright = ui.mr_yy_qsy;
	pyy_qsy_s->index = 3;
	md_symptom_info.push_back(pyy_no_s);
	md_symptom_info.push_back(pyy_single_s);
	md_symptom_info.push_back(pyy_multi_s);
	md_symptom_info.push_back(pyy_xx_s);
	md_symptom_info.push_back(pyy_yellow_s);
	md_symptom_info.push_back(pyy_ry_s);
	md_symptom_info.push_back(pyy_qsy_s);

	//左侧溢液单项
	symptom_info* pl_yy_no_s = new symptom_info();
	symptom_info* pl_yy_single_s = new symptom_info();
	symptom_info* pl_yy_multi_s = new symptom_info();
	symptom_info* pl_yy_xx_s = new symptom_info();
	symptom_info* pl_yy_yellow_s = new symptom_info();
	symptom_info* pl_yy_ry_s = new symptom_info();
	symptom_info* pl_yy_qsy_s = new symptom_info();
	//pl_yy_no_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液无"));
	//pl_yy_no_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜无"));
	//pl_yy_no_s->v_names.push_back(QString::fromLocal8Bit("左侧一页无"));
	read_config("/ini/yiye_config.ini", "l_yiye_no", pl_yy_no_s->v_names);
	pl_yy_no_s->pleft = ui.ml_yy_no;
	pl_yy_no_s->pright = nullptr;
	pl_yy_no_s->index = 31;
	//pl_yy_single_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液单管"));
	//pl_yy_single_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜单管"));
	//pl_yy_single_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜当管"));
	//pl_yy_single_s->v_names.push_back(QString::fromLocal8Bit("左侧一页单管"));
	//pl_yy_single_s->v_names.push_back(QString::fromLocal8Bit("左侧一页当管")); 
	read_config("/ini/yiye_config.ini", "l_yiye_danguan", pl_yy_single_s->v_names);
	pl_yy_single_s->pleft = ui.ml_yy_single;
	pl_yy_single_s->pright = nullptr;
	pl_yy_single_s->index = 31;
	//pl_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液多管"));
	//pl_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜多管"));
	//pl_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("左侧一页多管"));
	read_config("/ini/yiye_config.ini", "l_yiye_duoguan", pl_yy_multi_s->v_names);
	pl_yy_multi_s->pleft = ui.ml_yy_multi;
	pl_yy_multi_s->pright = nullptr;
	pl_yy_multi_s->index = 31;
	//pl_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液血性"));
	//pl_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜血性")); 
	//pl_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("左侧一页血性"));
	read_config("/ini/yiye_config.ini", "l_yiye_xuexing", pl_yy_xx_s->v_names);
	pl_yy_xx_s->pleft = ui.ml_yy_xx;
	pl_yy_xx_s->pright = nullptr;
	pl_yy_xx_s->index = 31;
	//pl_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液黄色"));
	//pl_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜黄色")); 
	//pl_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("左侧一页黄色")); 
	read_config("/ini/yiye_config.ini", "l_yiye_yellow", pl_yy_yellow_s->v_names);
	pl_yy_yellow_s->pleft = ui.ml_yy_yellow;
	pl_yy_yellow_s->pright = nullptr;
	pl_yy_yellow_s->index = 31;
	//pl_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液乳样"));
	//pl_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜茹样"));
	//pl_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜乳样")); 
	//pl_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("左侧一页茹样")); 
	//pl_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("左侧一页乳样"));
	read_config("/ini/yiye_config.ini", "l_yiye_ruyang", pl_yy_ry_s->v_names);
	pl_yy_ry_s->pleft = ui.ml_yy_ry;
	pl_yy_ry_s->pright = nullptr;
	pl_yy_ry_s->index = 31;
	//pl_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("左侧溢液清水样"));
	//pl_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("左侧一夜清水样")); 
	//pl_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("左侧一页清水样")); 
	read_config("/ini/yiye_config.ini", "l_yiye_qsy", pl_yy_qsy_s->v_names);
	pl_yy_qsy_s->pleft = ui.ml_yy_qsy;
	pl_yy_qsy_s->pright = nullptr;
	pl_yy_qsy_s->index = 31;
	md_symptom_info.push_back(pl_yy_no_s);
	md_symptom_info.push_back(pl_yy_single_s);
	md_symptom_info.push_back(pl_yy_multi_s);
	md_symptom_info.push_back(pl_yy_xx_s);
	md_symptom_info.push_back(pl_yy_yellow_s);
	md_symptom_info.push_back(pl_yy_ry_s);
	md_symptom_info.push_back(pl_yy_qsy_s);

	//右侧溢液单项
	symptom_info* pr_yy_no_s = new symptom_info();
	symptom_info* pr_yy_single_s = new symptom_info();
	symptom_info* pr_yy_multi_s = new symptom_info();
	symptom_info* pr_yy_xx_s = new symptom_info();
	symptom_info* pr_yy_yellow_s = new symptom_info();
	symptom_info* pr_yy_ry_s = new symptom_info();
	symptom_info* pr_yy_qsy_s = new symptom_info();
	//pr_yy_no_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液无"));
	//pr_yy_no_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜无"));
	//pr_yy_no_s->v_names.push_back(QString::fromLocal8Bit("右侧一页无"));
	read_config("/ini/yiye_config.ini", "r_yiye_no", pr_yy_no_s->v_names);
	pr_yy_no_s->pleft = nullptr;
	pr_yy_no_s->pright = ui.mr_yy_no;
	pr_yy_no_s->index = 32;
	//pr_yy_single_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液单管"));
	//pr_yy_single_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜单管"));
	//pr_yy_single_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜当管"));
	//pr_yy_single_s->v_names.push_back(QString::fromLocal8Bit("右侧一页单管")); 
	//pr_yy_single_s->v_names.push_back(QString::fromLocal8Bit("右侧一页当管")); 
	read_config("/ini/yiye_config.ini", "r_yiye_danguan", pr_yy_single_s->v_names);
	pr_yy_single_s->pleft = nullptr;
	pr_yy_single_s->pright = ui.mr_yy_single;
	pr_yy_single_s->index = 32;
	//pr_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液多管"));
	//pr_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜多管"));
	//pr_yy_multi_s->v_names.push_back(QString::fromLocal8Bit("右侧一页多管"));
	read_config("/ini/yiye_config.ini", "r_yiye_duoguan", pr_yy_multi_s->v_names);
	pr_yy_multi_s->pleft = nullptr;
	pr_yy_multi_s->pright = ui.mr_yy_multi;
	pr_yy_multi_s->index = 32;
	//pr_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液血性"));
	//pr_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜血性"));
	//pr_yy_xx_s->v_names.push_back(QString::fromLocal8Bit("右侧一页血性"));
	read_config("/ini/yiye_config.ini", "r_yiye_xuexing", pr_yy_xx_s->v_names);
	pr_yy_xx_s->pleft = nullptr;
	pr_yy_xx_s->pright = ui.mr_yy_xx;
	pr_yy_xx_s->index = 32;
	//pr_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液黄色")); 
	//pr_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜黄色")); 
	//pr_yy_yellow_s->v_names.push_back(QString::fromLocal8Bit("右侧一页黄色")); 
	read_config("/ini/yiye_config.ini", "r_yiye_yellow", pr_yy_yellow_s->v_names);
	pr_yy_yellow_s->pleft = nullptr;
	pr_yy_yellow_s->pright = ui.mr_yy_yellow;
	pr_yy_yellow_s->index = 32;
	//pr_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液乳样"));
	//pr_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜茹样")); 
	//pr_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜乳样"));
	//pr_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("右侧一页茹样"));
	//pr_yy_ry_s->v_names.push_back(QString::fromLocal8Bit("右侧一页乳样"));
	read_config("/ini/yiye_config.ini", "r_yiye_ruyang", pr_yy_ry_s->v_names);
	pr_yy_ry_s->pleft = nullptr;
	pr_yy_ry_s->pright = ui.mr_yy_ry;
	pr_yy_ry_s->index = 32;
	//pr_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("右侧溢液清水样")); 
	//pr_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("右侧一夜清水样")); 
	//pr_yy_qsy_s->v_names.push_back(QString::fromLocal8Bit("右侧一页清水样")); 
	read_config("/ini/yiye_config.ini", "r_yiye_qsy", pr_yy_qsy_s->v_names);
	pr_yy_qsy_s->pleft = nullptr;
	pr_yy_qsy_s->pright = ui.mr_yy_qsy;
	pr_yy_qsy_s->index = 32;
	md_symptom_info.push_back(pr_yy_no_s);
	md_symptom_info.push_back(pr_yy_single_s);
	md_symptom_info.push_back(pr_yy_multi_s);
	md_symptom_info.push_back(pr_yy_xx_s);
	md_symptom_info.push_back(pr_yy_yellow_s);
	md_symptom_info.push_back(pr_yy_ry_s);
	md_symptom_info.push_back(pr_yy_qsy_s);
}

//腺体信息
void record64::init_xianti_info()
{
	//腺体
	symptom_info* pxt_normal = new symptom_info();
	symptom_info* pxt_txz = new symptom_info();
	symptom_info* pxt_jxxzh = new symptom_info();
	symptom_info* pxt_zk = new symptom_info();
	symptom_info* pxt_jjxzh = new symptom_info();
	//pxt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/xianti_config.ini", "xianti_normal", pxt_normal->v_names);
	pxt_normal->pleft = ui.ml_xt_normal;
	pxt_normal->pright = ui.mr_xt_normal;
	pxt_normal->index = 4;
	//pxt_txz->v_names.push_back(QString::fromLocal8Bit("条絮状")); 
	//pxt_txz->v_names.push_back(QString::fromLocal8Bit("调序中")); 
	//pxt_txz->v_names.push_back(QString::fromLocal8Bit("调序状"));
	read_config("/ini/xianti_config.ini", "xianti_txz", pxt_txz->v_names);
	pxt_txz->pleft = ui.ml_xt_txz;
	pxt_txz->pright = ui.mr_xt_txz;
	pxt_txz->index = 4;
	//pxt_jxxzh->v_names.push_back(QString::fromLocal8Bit("局限性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jxxzh", pxt_jxxzh->v_names);
	pxt_jxxzh->pleft = ui.ml_xt_jxxzh;
	pxt_jxxzh->pright = ui.mr_xt_jxxzh;
	pxt_jxxzh->index = 4;
	//pxt_zk->v_names.push_back(QString::fromLocal8Bit("肿块")); 
	//pxt_zk->v_names.push_back(QString::fromLocal8Bit("中框")); 
	//pxt_zk->v_names.push_back(QString::fromLocal8Bit("中快"));
	read_config("/ini/xianti_config.ini", "xianti_zhongkuai", pxt_zk->v_names);
	pxt_zk->pleft = ui.ml_xt_zk;
	pxt_zk->pright = ui.mr_xt_zk;
	pxt_zk->index = 4;
	//pxt_jjxzh->v_names.push_back(QString::fromLocal8Bit("结节性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jjxzh", pxt_jjxzh->v_names);
	pxt_jjxzh->pleft = ui.ml_xt_jjxzh;
	pxt_jjxzh->pright = ui.mr_xt_jjxzh;
	pxt_jjxzh->index = 4;
	v_breast_xt.push_back(pxt_normal);
	v_breast_xt.push_back(pxt_txz);
	v_breast_xt.push_back(pxt_jxxzh);
	v_breast_xt.push_back(pxt_zk);
	v_breast_xt.push_back(pxt_jjxzh);
	breast_info* pxt = new breast_info();
	//pxt->v_names.push_back(QString::fromLocal8Bit("腺体"));
	//pxt->v_names.push_back(QString::fromLocal8Bit("占比")); 
	read_config("/ini/xianti_config.ini", "xianti", pxt->v_names);
	pxt->vinfo = v_breast_xt;
	pxt->pdefault = pxt_normal;
	md_breast.push_back(pxt);

	//左侧腺体
	symptom_info* pl_xt_normal = new symptom_info();
	symptom_info* pl_xt_txz = new symptom_info();
	symptom_info* pl_xt_jxxzh = new symptom_info();
	symptom_info* pl_xt_zk = new symptom_info();
	symptom_info* pl_xt_jjxzh = new symptom_info();
	//pl_xt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/xianti_config.ini", "xianti_normal", pl_xt_normal->v_names);
	pl_xt_normal->pleft = ui.ml_xt_normal;
	pl_xt_normal->pright = nullptr;
	pl_xt_normal->index = 41;
	//pl_xt_txz->v_names.push_back(QString::fromLocal8Bit("条絮状"));
	read_config("/ini/xianti_config.ini", "xianti_txz", pl_xt_txz->v_names);
	pl_xt_txz->pleft = ui.ml_xt_txz;
	pl_xt_txz->pright = nullptr;
	pl_xt_txz->index = 41;
	//pl_xt_jxxzh->v_names.push_back(QString::fromLocal8Bit("局限性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jxxzh", pl_xt_jxxzh->v_names);
	pl_xt_jxxzh->pleft = ui.ml_xt_jxxzh;
	pl_xt_jxxzh->pright = nullptr;
	pl_xt_jxxzh->index = 41;
	//pl_xt_zk->v_names.push_back(QString::fromLocal8Bit("肿块"));
	read_config("/ini/xianti_config.ini", "xianti_zhongkuai", pl_xt_zk->v_names);
	pl_xt_zk->pleft = ui.ml_xt_zk;
	pl_xt_zk->pright = nullptr;
	pl_xt_zk->index = 41;
	//pl_xt_jjxzh->v_names.push_back(QString::fromLocal8Bit("结节性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jjxzh", pl_xt_jjxzh->v_names);
	pl_xt_jjxzh->pleft = ui.ml_xt_jjxzh;
	pl_xt_jjxzh->pright = nullptr;
	pl_xt_jjxzh->index = 41;
	v_breast_l_xt.push_back(pl_xt_normal);
	v_breast_l_xt.push_back(pl_xt_txz);
	v_breast_l_xt.push_back(pl_xt_jxxzh);
	v_breast_l_xt.push_back(pl_xt_zk);
	v_breast_l_xt.push_back(pl_xt_jjxzh);
	breast_info* pl_xt = new breast_info();
	//pl_xt->v_names.push_back(QString::fromLocal8Bit("左侧腺体"));
	read_config("/ini/xianti_config.ini", "l_xianti", pl_xt->v_names);
	pl_xt->vinfo = v_breast_xt;
	pl_xt->pdefault = pl_xt_normal;
	md_breast.push_back(pl_xt);

	//右侧腺体
	symptom_info* pr_xt_normal = new symptom_info();
	symptom_info* pr_xt_txz = new symptom_info();
	symptom_info* pr_xt_jxxzh = new symptom_info();
	symptom_info* pr_xt_zk = new symptom_info();
	symptom_info* pr_xt_jjxzh = new symptom_info();
	//pr_xt_normal->v_names.push_back(QString::fromLocal8Bit("正常"));
	read_config("/ini/xianti_config.ini", "xianti_normal", pr_xt_normal->v_names);
	pr_xt_normal->pleft = nullptr;
	pr_xt_normal->pright = ui.mr_xt_normal;
	pr_xt_normal->index = 42;
	//pr_xt_txz->v_names.push_back(QString::fromLocal8Bit("条絮状"));
	read_config("/ini/xianti_config.ini", "xianti_txz", pr_xt_txz->v_names);
	pr_xt_txz->pleft = nullptr;
	pr_xt_txz->pright = ui.mr_xt_txz;
	pr_xt_txz->index = 42;
	//pr_xt_jxxzh->v_names.push_back(QString::fromLocal8Bit("局限性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jxxzh", pr_xt_jxxzh->v_names);
	pr_xt_jxxzh->pleft = nullptr;
	pr_xt_jxxzh->pright = ui.mr_xt_jxxzh;
	pr_xt_jxxzh->index = 42;
	//pr_xt_zk->v_names.push_back(QString::fromLocal8Bit("肿块"));
	read_config("/ini/xianti_config.ini", "xianti_zhongkuai", pr_xt_zk->v_names);
	pr_xt_zk->pleft = nullptr;
	pr_xt_zk->pright = ui.mr_xt_zk;
	pr_xt_zk->index = 42;
	//pr_xt_jjxzh->v_names.push_back(QString::fromLocal8Bit("结节性增厚"));
	read_config("/ini/xianti_config.ini", "xianti_jjxzh", pr_xt_jjxzh->v_names);
	pr_xt_jjxzh->pleft = nullptr;
	pr_xt_jjxzh->pright = ui.mr_xt_jjxzh;
	pr_xt_jjxzh->index = 42;
	v_breast_r_xt.push_back(pr_xt_normal);
	v_breast_r_xt.push_back(pr_xt_txz);
	v_breast_r_xt.push_back(pr_xt_jxxzh);
	v_breast_r_xt.push_back(pr_xt_zk);
	v_breast_r_xt.push_back(pr_xt_jjxzh);
	breast_info* pr_xt = new breast_info();
	//pr_xt->v_names.push_back(QString::fromLocal8Bit("右侧腺体"));
	read_config("/ini/xianti_config.ini", "r_xianti", pr_xt->v_names);
	pr_xt->vinfo = v_breast_xt;
	pr_xt->pdefault = pr_xt_normal;
	md_breast.push_back(pr_xt);

	//腺体单项
	symptom_info* pxt_normal_s = new symptom_info();
	symptom_info* pxt_txz_s = new symptom_info();
	symptom_info* pxt_jxxzh_s = new symptom_info();
	symptom_info* pxt_zk_s = new symptom_info();
	symptom_info* pxt_jjxzh_s = new symptom_info();
	//pxt_normal_s->v_names.push_back(QString::fromLocal8Bit("腺体正常"));
	read_config("/ini/xianti_config.ini", "xianti_all_normal", pxt_normal_s->v_names);
	pxt_normal_s->pleft = ui.ml_xt_normal;
	pxt_normal_s->pright = ui.mr_xt_normal;
	pxt_normal_s->index = 4;
	//pxt_txz_s->v_names.push_back(QString::fromLocal8Bit("腺体条絮状"));
	//pxt_txz_s->v_names.push_back(QString::fromLocal8Bit("电梯条絮状")); 
	read_config("/ini/xianti_config.ini", "xianti_all_txz", pxt_txz_s->v_names);
	pxt_txz_s->pleft = ui.ml_xt_txz;
	pxt_txz_s->pright = ui.mr_xt_txz;
	pxt_txz_s->index = 4;
	//pxt_jxxzh_s->v_names.push_back(QString::fromLocal8Bit("腺体局限性增厚"));
	//pxt_jxxzh_s->v_names.push_back(QString::fromLocal8Bit("面体局限性增厚")); 
	read_config("/ini/xianti_config.ini", "xianti_all_jxxzh", pxt_jxxzh_s->v_names);
	pxt_jxxzh_s->pleft = ui.ml_xt_jxxzh;
	pxt_jxxzh_s->pright = ui.mr_xt_jxxzh;
	pxt_jxxzh_s->index = 4;
	//pxt_zk_s->v_names.push_back(QString::fromLocal8Bit("腺体肿块")); 
	//pxt_zk_s->v_names.push_back(QString::fromLocal8Bit("现体重快")); 
	read_config("/ini/xianti_config.ini", "xianti_all_zhongkuai", pxt_zk_s->v_names);
	pxt_zk_s->pleft = ui.ml_xt_zk;
	pxt_zk_s->pright = ui.mr_xt_zk;
	pxt_zk_s->index = 4;
	//pxt_jjxzh_s->v_names.push_back(QString::fromLocal8Bit("腺体结节性增厚"));
	//pxt_jjxzh_s->v_names.push_back(QString::fromLocal8Bit("腺体结节性丰厚"));
	//pxt_jjxzh_s->v_names.push_back(QString::fromLocal8Bit("腺体结节性账号")); 
	read_config("/ini/xianti_config.ini", "xianti_all_jxxzh", pxt_jjxzh_s->v_names);
	pxt_jjxzh_s->pleft = ui.ml_xt_jjxzh;
	pxt_jjxzh_s->pright = ui.mr_xt_jjxzh;
	pxt_jjxzh_s->index = 4;
	md_symptom_info.push_back(pxt_normal_s);
	md_symptom_info.push_back(pxt_txz_s);
	md_symptom_info.push_back(pxt_jxxzh_s);
	md_symptom_info.push_back(pxt_zk_s);
	md_symptom_info.push_back(pxt_jjxzh_s);

	//左侧腺体单项
	symptom_info* pl_xt_normal_s = new symptom_info();
	symptom_info* pl_xt_txz_s = new symptom_info();
	symptom_info* pl_xt_jxxzh_s = new symptom_info();
	symptom_info* pl_xt_zk_s = new symptom_info();
	symptom_info* pl_xt_jjxzh_s = new symptom_info();
	//pl_xt_normal_s->v_names.push_back(QString::fromLocal8Bit("左侧腺体正常"));
	read_config("/ini/xianti_config.ini", "l_xianti_normal", pl_xt_normal_s->v_names);
	pl_xt_normal_s->pleft = ui.ml_xt_normal;
	pl_xt_normal_s->pright = nullptr;
	pl_xt_normal_s->index = 41;
	//pl_xt_txz_s->v_names.push_back(QString::fromLocal8Bit("左侧腺体条絮状"));
	read_config("/ini/xianti_config.ini", "l_xianti_txz", pl_xt_txz_s->v_names);
	pl_xt_txz_s->pleft = ui.ml_xt_txz;
	pl_xt_txz_s->pright = nullptr;
	pl_xt_txz_s->index = 41;
	//pl_xt_jxxzh_s->v_names.push_back(QString::fromLocal8Bit("左侧腺体局限性增厚")); 
	read_config("/ini/xianti_config.ini", "l_xianti_jxxzh", pl_xt_jxxzh_s->v_names);
	pl_xt_jxxzh_s->pleft = ui.ml_xt_jxxzh;
	pl_xt_jxxzh_s->pright = nullptr;
	pl_xt_jxxzh_s->index = 41;
	//pl_xt_zk_s->v_names.push_back(QString::fromLocal8Bit("左侧腺体肿块"));
	read_config("/ini/xianti_config.ini", "l_xianti_zhongkuai", pl_xt_zk_s->v_names);
	pl_xt_zk_s->pleft = ui.ml_xt_zk;
	pl_xt_zk_s->pright = nullptr;
	pl_xt_zk_s->index = 41;
	//pl_xt_jjxzh_s->v_names.push_back(QString::fromLocal8Bit("左侧腺体结节性增厚"));
	read_config("/ini/xianti_config.ini", "l_xianti_jjxzh", pl_xt_jjxzh_s->v_names);
	pl_xt_jjxzh_s->pleft = ui.ml_xt_jjxzh;
	pl_xt_jjxzh_s->pright = nullptr;
	pl_xt_jjxzh_s->index = 41;
	md_symptom_info.push_back(pl_xt_normal_s);
	md_symptom_info.push_back(pl_xt_txz_s);
	md_symptom_info.push_back(pl_xt_jxxzh_s);
	md_symptom_info.push_back(pl_xt_zk_s);
	md_symptom_info.push_back(pl_xt_jjxzh_s);

	//右侧腺体单项
	symptom_info* pr_xt_normal_s = new symptom_info();
	symptom_info* pr_xt_txz_s = new symptom_info();
	symptom_info* pr_xt_jxxzh_s = new symptom_info();
	symptom_info* pr_xt_zk_s = new symptom_info();
	symptom_info* pr_xt_jjxzh_s = new symptom_info();
	//pr_xt_normal_s->v_names.push_back(QString::fromLocal8Bit("右侧腺体正常"));
	read_config("/ini/xianti_config.ini", "r_xianti_normal", pr_xt_normal_s->v_names);
	pr_xt_normal_s->pleft = nullptr;
	pr_xt_normal_s->pright = ui.mr_xt_normal;
	pr_xt_normal_s->index = 42;
	//pr_xt_txz_s->v_names.push_back(QString::fromLocal8Bit("右侧腺体条絮状"));
	read_config("/ini/xianti_config.ini", "r_xianti_txz", pr_xt_txz_s->v_names);
	pr_xt_txz_s->pleft = nullptr;
	pr_xt_txz_s->pright = ui.mr_xt_txz;
	pr_xt_txz_s->index = 42;
	//pr_xt_jxxzh_s->v_names.push_back(QString::fromLocal8Bit("右侧腺体局限性增厚"));
	read_config("/ini/xianti_config.ini", "r_xianti_jxxzh", pr_xt_jxxzh_s->v_names);
	pr_xt_jxxzh_s->pleft = nullptr;
	pr_xt_jxxzh_s->pright = ui.mr_xt_jxxzh;
	pr_xt_jxxzh_s->index = 42;
	//pr_xt_zk_s->v_names.push_back(QString::fromLocal8Bit("右侧腺体肿块"));
	read_config("/ini/xianti_config.ini", "r_xianti_zhongkuai", pr_xt_zk_s->v_names);
	pr_xt_zk_s->pleft = nullptr;
	pr_xt_zk_s->pright = ui.mr_xt_zk;
	pr_xt_zk_s->index = 42;
	//pr_xt_jjxzh_s->v_names.push_back(QString::fromLocal8Bit("右侧腺体结节性增厚"));
	read_config("/ini/xianti_config.ini", "r_xianti_jjxzh", pr_xt_jjxzh_s->v_names);
	pr_xt_jjxzh_s->pleft = nullptr;
	pr_xt_jjxzh_s->pright = ui.mr_xt_jjxzh;
	pr_xt_jjxzh_s->index = 42;
	md_symptom_info.push_back(pr_xt_normal_s);
	md_symptom_info.push_back(pr_xt_txz_s);
	md_symptom_info.push_back(pr_xt_jxxzh_s);
	md_symptom_info.push_back(pr_xt_zk_s);
	md_symptom_info.push_back(pr_xt_jjxzh_s);
}

//副乳信息
void record64::init_furu_info()
{
	//副乳
	symptom_info* pfr_yes = new symptom_info();
	symptom_info* pfr_no = new symptom_info();
	//pfr_yes->v_names.push_back(QString::fromLocal8Bit("有"));
	read_config("/ini/furu_config.ini", "furu_yes", pfr_yes->v_names);
	pfr_yes->pleft = ui.ml_fr_yes;
	pfr_yes->pright = ui.mr_fr_yes;
	pfr_yes->index = 5;
	//pfr_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pfr_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/furu_config.ini", "furu_no", pfr_no->v_names);
	pfr_no->pleft = ui.ml_fr_no;
	pfr_no->pright = ui.mr_fr_no;
	pfr_no->index = 5;
	v_breast_fr.push_back(pfr_yes);
	v_breast_fr.push_back(pfr_no);
	breast_info* pfr = new breast_info();
	//pfr->v_names.push_back(QString::fromLocal8Bit("副乳"));
	//pfr->v_names.push_back(QString::fromLocal8Bit("腐乳"));
	//pfr->v_names.push_back(QString::fromLocal8Bit("妇孺"));
	//pfr->v_names.push_back(QString::fromLocal8Bit("腐儒")); 
	//pfr->v_names.push_back(QString::fromLocal8Bit("富如"));
	//pfr->v_names.push_back(QString::fromLocal8Bit("妇容"));
	//pfr->v_names.push_back(QString::fromLocal8Bit("富有")); 
	read_config("/ini/furu_config.ini", "furu", pfr->v_names);
	pfr->vinfo = v_breast_fr;
	pfr->pdefault = pfr_no;
	md_breast.push_back(pfr);

	//左侧副乳
	symptom_info* pl_fr_yes = new symptom_info();
	symptom_info* pl_fr_no = new symptom_info();
	//pl_fr_yes->v_names.push_back(QString::fromLocal8Bit("有"));
	read_config("/ini/furu_config.ini", "furu_yes", pl_fr_yes->v_names);
	pl_fr_yes->pleft = ui.ml_fr_yes;
	pl_fr_yes->pright = nullptr;
	pl_fr_yes->index = 51;
	//pl_fr_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pl_fr_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/furu_config.ini", "furu_no", pl_fr_no->v_names);
	pl_fr_no->pleft = ui.ml_fr_no;
	pl_fr_no->pright = nullptr;
	pl_fr_no->index = 51;
	v_breast_l_fr.push_back(pl_fr_yes);
	v_breast_l_fr.push_back(pl_fr_no);
	breast_info* pl_fr = new breast_info();
	//pl_fr->v_names.push_back(QString::fromLocal8Bit("左侧副乳"));
	//pl_fr->v_names.push_back(QString::fromLocal8Bit("左侧附入")); 
	//pl_fr->v_names.push_back(QString::fromLocal8Bit("左侧腹乳"));
	read_config("/ini/furu_config.ini", "l_furu", pl_fr->v_names);
	pl_fr->vinfo = v_breast_l_fr;
	pl_fr->pdefault = pl_fr_no;
	md_breast.push_back(pl_fr);

	//右侧副乳
	symptom_info* pr_fr_yes = new symptom_info();
	symptom_info* pr_fr_no = new symptom_info();
	//pr_fr_yes->v_names.push_back(QString::fromLocal8Bit("有"));
	read_config("/ini/furu_config.ini", "furu_yes", pr_fr_yes->v_names);
	pr_fr_yes->pleft = nullptr;
	pr_fr_yes->pright = ui.mr_fr_yes;
	pr_fr_yes->index = 52;
	//pr_fr_no->v_names.push_back(QString::fromLocal8Bit("无"));
	//pr_fr_no->v_names.push_back(QString::fromLocal8Bit("吴"));
	read_config("/ini/furu_config.ini", "furu_no", pr_fr_no->v_names);
	pr_fr_no->pleft = nullptr;
	pr_fr_no->pright = ui.mr_fr_no;
	pr_fr_no->index = 52;
	v_breast_r_fr.push_back(pr_fr_yes);
	v_breast_r_fr.push_back(pr_fr_no);
	breast_info* pr_fr = new breast_info();
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("右侧副乳"));
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("右侧附入"));
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("右侧腹乳"));
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("用侧副乳"));
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("用侧附入"));
	//pr_fr->v_names.push_back(QString::fromLocal8Bit("用侧腹乳")); 
	read_config("/ini/furu_config.ini", "r_furu", pr_fr->v_names);
	pr_fr->vinfo = v_breast_fr;
	pr_fr->pdefault = pr_fr_no;
	md_breast.push_back(pr_fr);

	//副乳单项
	symptom_info* pfr_yes_s = new symptom_info();
	symptom_info* pfr_no_s = new symptom_info();
	//pfr_yes_s->v_names.push_back(QString::fromLocal8Bit("副乳有"));
	//pfr_yes_s->v_names.push_back(QString::fromLocal8Bit("慕容有"));
	//pfr_yes_s->v_names.push_back(QString::fromLocal8Bit("傅如有"));
	//pfr_yes_s->v_names.push_back(QString::fromLocal8Bit("富如有")); 
	read_config("/ini/furu_config.ini", "furu_all_yes", pfr_yes_s->v_names);
	pfr_yes_s->pleft = ui.ml_fr_yes;
	pfr_yes_s->pright = ui.mr_fr_yes;
	pfr_yes_s->index = 5;
	//pfr_no_s->v_names.push_back(QString::fromLocal8Bit("副乳无"));
	read_config("/ini/furu_config.ini", "furu_all_no", pfr_no_s->v_names);
	pfr_no_s->pleft = ui.ml_fr_no;
	pfr_no_s->pright = ui.mr_fr_no;
	pfr_no_s->index = 5;
	md_symptom_info.push_back(pfr_yes_s);
	md_symptom_info.push_back(pfr_no_s);

	//左侧副乳单项
	symptom_info* pl_fr_yes_s = new symptom_info();
	symptom_info* pl_fr_no_s = new symptom_info();
	//pl_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("左侧副乳有"));
	//pl_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("左侧附入有"));
	//pl_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("左侧腹乳有"));
	read_config("/ini/furu_config.ini", "l_furu_yes", pl_fr_yes_s->v_names);
	pl_fr_yes_s->pleft = ui.ml_fr_yes;
	pl_fr_yes_s->pright = nullptr;
	pl_fr_yes_s->index = 51;
	//pl_fr_no_s->v_names.push_back(QString::fromLocal8Bit("左侧副乳无"));
	//pl_fr_no_s->v_names.push_back(QString::fromLocal8Bit("左侧附入无"));
	//pl_fr_no_s->v_names.push_back(QString::fromLocal8Bit("左侧腹乳无"));
	read_config("/ini/furu_config.ini", "l_furu_no", pl_fr_no_s->v_names);
	pl_fr_no_s->pleft = ui.ml_fr_no;
	pl_fr_no_s->pright = nullptr;
	pl_fr_no_s->index = 51;
	md_symptom_info.push_back(pl_fr_yes_s);
	md_symptom_info.push_back(pl_fr_no_s);

	//右侧副乳单项
	symptom_info* pr_fr_yes_s = new symptom_info();
	symptom_info* pr_fr_no_s = new symptom_info();
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("右侧副乳有"));
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("右侧附入有"));
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("右侧腹乳有"));
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("用侧副乳有"));
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("用侧附入有"));
	//pr_fr_yes_s->v_names.push_back(QString::fromLocal8Bit("用侧腹乳有")); 
	read_config("/ini/furu_config.ini", "r_furu_yes", pr_fr_yes_s->v_names);
	pr_fr_yes_s->pleft = nullptr;
	pr_fr_yes_s->pright = ui.mr_fr_yes;
	pr_fr_yes_s->index = 52;
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("右侧副乳无"));
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("右侧附入无"));
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("右侧腹乳无"));
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("用侧副乳无"));
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("用侧附入无"));
	//pr_fr_no_s->v_names.push_back(QString::fromLocal8Bit("用侧腹乳无"));
	read_config("/ini/furu_config.ini", "r_furu_no", pr_fr_no_s->v_names);
	pr_fr_no_s->pleft = nullptr;
	pr_fr_no_s->pright = ui.mr_fr_no;
	pr_fr_no_s->index = 52;
	md_symptom_info.push_back(pr_fr_yes_s);
	md_symptom_info.push_back(pr_fr_no_s);
}

//疼痛信息
void record64::init_tengtong_info()
{
	//疼痛
	symptom_info* ptt_dt = new symptom_info();
	symptom_info* ptt_jcxtt = new symptom_info();
	symptom_info* ptt_jqtt = new symptom_info();
	symptom_info* ptt_zt = new symptom_info();
	symptom_info* ptt_rt = new symptom_info();
	symptom_info* ptt_no = new symptom_info();
	//ptt_dt->v_names.push_back(QString::fromLocal8Bit("钝痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_duntong", ptt_dt->v_names);
	ptt_dt->pleft = ui.ml_tt_dt;
	ptt_dt->pright = ui.mr_tt_dt;
	ptt_dt->index = 6;
	//ptt_jcxtt->v_names.push_back(QString::fromLocal8Bit("经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jcxtt", ptt_jcxtt->v_names);
	ptt_jcxtt->pleft = ui.ml_tt_jcxtt;
	ptt_jcxtt->pright = ui.mr_tt_jcxtt;
	ptt_jcxtt->index = 6;
	//ptt_jqtt->v_names.push_back(QString::fromLocal8Bit("经期疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jqtt", ptt_jqtt->v_names);
	ptt_jqtt->pleft = ui.ml_tt_jqtt;
	ptt_jqtt->pright = ui.mr_tt_jqtt;
	ptt_jqtt->index = 6;
	//ptt_zt->v_names.push_back(QString::fromLocal8Bit("胀痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_zhangtong", ptt_zt->v_names);
	ptt_zt->pleft = ui.ml_tt_zt;
	ptt_zt->pright = ui.mr_tt_zt;
	ptt_zt->index = 6;
	//ptt_rt->v_names.push_back(QString::fromLocal8Bit("锐痛"));
	//ptt_rt->v_names.push_back(QString::fromLocal8Bit("热一通")); 
	read_config("/ini/tengtong_config.ini", "tengtong_ruitong", ptt_rt->v_names);
	ptt_rt->pleft = ui.ml_tt_rt;
	ptt_rt->pright = ui.mr_tt_rt;
	ptt_rt->index = 6;
	//ptt_no->v_names.push_back(QString::fromLocal8Bit("否"));
	read_config("/ini/tengtong_config.ini", "tengtong_no", ptt_no->v_names);
	ptt_no->pleft = ui.ml_tt_no;
	ptt_no->pright = ui.mr_tt_no;
	ptt_no->index = 6;
	v_breast_tt.push_back(ptt_dt);
	v_breast_tt.push_back(ptt_jcxtt);
	v_breast_tt.push_back(ptt_jqtt);
	v_breast_tt.push_back(ptt_zt);
	v_breast_tt.push_back(ptt_rt);
	v_breast_tt.push_back(ptt_no);
	breast_info* ptt = new breast_info();
	//ptt->v_names.push_back(QString::fromLocal8Bit("疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong", ptt->v_names);
	ptt->vinfo = v_breast_tt;
	ptt->pdefault = ptt_no;
	md_breast.push_back(ptt);

	//左侧疼痛
	symptom_info* pl_tt_dt = new symptom_info();
	symptom_info* pl_tt_jcxtt = new symptom_info();
	symptom_info* pl_tt_jqtt = new symptom_info();
	symptom_info* pl_tt_zt = new symptom_info();
	symptom_info* pl_tt_rt = new symptom_info();
	symptom_info* pl_tt_no = new symptom_info();
	//pl_tt_dt->v_names.push_back(QString::fromLocal8Bit("钝痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_duntong", pl_tt_dt->v_names);
	pl_tt_dt->pleft = ui.ml_tt_dt;
	pl_tt_dt->pright = nullptr;
	pl_tt_dt->index = 61;
	//pl_tt_jcxtt->v_names.push_back(QString::fromLocal8Bit("经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jcxtt", pl_tt_jcxtt->v_names);
	pl_tt_jcxtt->pleft = ui.ml_tt_jcxtt;
	pl_tt_jcxtt->pright = nullptr;
	pl_tt_jcxtt->index = 61;
	//pl_tt_jqtt->v_names.push_back(QString::fromLocal8Bit("经期疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jqtt", pl_tt_jqtt->v_names);
	pl_tt_jqtt->pleft = ui.ml_tt_jqtt;
	pl_tt_jqtt->pright = nullptr;
	pl_tt_jqtt->index = 61;
	//pl_tt_zt->v_names.push_back(QString::fromLocal8Bit("胀痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_zhangtong", pl_tt_zt->v_names);
	pl_tt_zt->pleft = ui.ml_tt_zt;
	pl_tt_zt->pright = nullptr;
	pl_tt_zt->index = 61;
	//pl_tt_rt->v_names.push_back(QString::fromLocal8Bit("锐痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_ruitong", pl_tt_rt->v_names);
	pl_tt_rt->pleft = ui.ml_tt_rt;
	pl_tt_rt->pright = nullptr;
	pl_tt_rt->index = 61;
	//pl_tt_no->v_names.push_back(QString::fromLocal8Bit("否"));
	read_config("/ini/tengtong_config.ini", "tengtong_no", pl_tt_no->v_names);
	pl_tt_no->pleft = ui.ml_tt_no;
	pl_tt_no->pright = nullptr;
	pl_tt_no->index = 61;
	v_breast_l_tt.push_back(pl_tt_dt);
	v_breast_l_tt.push_back(pl_tt_jcxtt);
	v_breast_l_tt.push_back(pl_tt_jqtt);
	v_breast_l_tt.push_back(pl_tt_zt);
	v_breast_l_tt.push_back(pl_tt_rt);
	v_breast_l_tt.push_back(pl_tt_no);
	breast_info* pl_tt = new breast_info();
	//pl_tt->v_names.push_back(QString::fromLocal8Bit("左侧疼痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong", pl_tt->v_names);
	pl_tt->vinfo = v_breast_l_tt;
	pl_tt->pdefault = pl_tt_no;
	md_breast.push_back(pl_tt);

	//右侧疼痛
	symptom_info* pr_tt_dt = new symptom_info();
	symptom_info* pr_tt_jcxtt = new symptom_info();
	symptom_info* pr_tt_jqtt = new symptom_info();
	symptom_info* pr_tt_zt = new symptom_info();
	symptom_info* pr_tt_rt = new symptom_info();
	symptom_info* pr_tt_no = new symptom_info();
	//pr_tt_dt->v_names.push_back(QString::fromLocal8Bit("钝痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_duntong", pr_tt_dt->v_names);
	pr_tt_dt->pleft = nullptr;
	pr_tt_dt->pright = ui.mr_tt_dt;
	pr_tt_dt->index = 62;
	//pr_tt_jcxtt->v_names.push_back(QString::fromLocal8Bit("经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jcxtt", pr_tt_jcxtt->v_names);
	pr_tt_jcxtt->pleft = nullptr;
	pr_tt_jcxtt->pright = ui.mr_tt_jcxtt;
	pr_tt_jcxtt->index = 62;
	//pr_tt_jqtt->v_names.push_back(QString::fromLocal8Bit("经期疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_jqtt", pr_tt_jqtt->v_names);
	pr_tt_jqtt->pleft = nullptr;
	pr_tt_jqtt->pright = ui.mr_tt_jqtt;
	pr_tt_jqtt->index = 62;
	//pr_tt_zt->v_names.push_back(QString::fromLocal8Bit("胀痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_zhangtong", pr_tt_zt->v_names);
	pr_tt_zt->pleft = nullptr;
	pr_tt_zt->pright = ui.mr_tt_zt;
	pr_tt_zt->index = 62;
	//pr_tt_rt->v_names.push_back(QString::fromLocal8Bit("锐痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_ruitong", pr_tt_rt->v_names);
	pr_tt_rt->pleft = nullptr;
	pr_tt_rt->pright = ui.mr_tt_rt;
	pr_tt_rt->index = 62;
	//pr_tt_no->v_names.push_back(QString::fromLocal8Bit("否"));
	read_config("/ini/tengtong_config.ini", "tengtong_no", pr_tt_no->v_names);
	pr_tt_no->pleft = nullptr;
	pr_tt_no->pright = ui.mr_tt_no;
	pr_tt_no->index = 62;
	v_breast_r_tt.push_back(pr_tt_dt);
	v_breast_r_tt.push_back(pr_tt_jcxtt);
	v_breast_r_tt.push_back(pr_tt_jqtt);
	v_breast_r_tt.push_back(pr_tt_zt);
	v_breast_r_tt.push_back(pr_tt_rt);
	v_breast_r_tt.push_back(pr_tt_no);
	breast_info* pr_tt = new breast_info();
	//pr_tt->v_names.push_back(QString::fromLocal8Bit("右侧疼痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong", pr_tt->v_names);
	pr_tt->vinfo = v_breast_r_tt;
	pr_tt->pdefault = pr_tt_no;
	md_breast.push_back(pr_tt);

	//疼痛单项
	symptom_info* ptt_dt_s = new symptom_info();
	symptom_info* ptt_jcxtt_s = new symptom_info();
	symptom_info* ptt_jqtt_s = new symptom_info();
	symptom_info* ptt_zt_s = new symptom_info();
	symptom_info* ptt_rt_s = new symptom_info();
	symptom_info* ptt_no_s = new symptom_info();
	//ptt_dt_s->v_names.push_back(QString::fromLocal8Bit("疼痛钝痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_duntong", ptt_dt_s->v_names);
	ptt_dt_s->pleft = ui.ml_tt_dt;
	ptt_dt_s->pright = ui.mr_tt_dt;
	ptt_dt_s->index = 6;
	//ptt_jcxtt_s->v_names.push_back(QString::fromLocal8Bit("疼痛经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_jcxtt", ptt_jcxtt_s->v_names);
	ptt_jcxtt_s->pleft = ui.ml_tt_jcxtt;
	ptt_jcxtt_s->pright = ui.mr_tt_jcxtt;
	ptt_jcxtt_s->index = 6;
	//ptt_jqtt_s->v_names.push_back(QString::fromLocal8Bit("疼痛经期疼痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_jqtt", ptt_jqtt_s->v_names);
	ptt_jqtt_s->pleft = ui.ml_tt_jqtt;
	ptt_jqtt_s->pright = ui.mr_tt_jqtt;
	ptt_jqtt_s->index = 6;
	//ptt_zt_s->v_names.push_back(QString::fromLocal8Bit("疼痛胀痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_zhangtong", ptt_zt_s->v_names);
	ptt_zt_s->pleft = ui.ml_tt_zt;
	ptt_zt_s->pright = ui.mr_tt_zt;
	ptt_zt_s->index = 6;
	//ptt_rt_s->v_names.push_back(QString::fromLocal8Bit("疼痛锐痛"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_ruitong", ptt_rt_s->v_names);
	ptt_rt_s->pleft = ui.ml_tt_rt;
	ptt_rt_s->pright = ui.mr_tt_rt;
	ptt_rt_s->index = 6;
	//ptt_no_s->v_names.push_back(QString::fromLocal8Bit("疼痛否"));
	read_config("/ini/tengtong_config.ini", "tengtong_all_no", ptt_no_s->v_names);
	ptt_no_s->pleft = ui.ml_tt_no;
	ptt_no_s->pright = ui.mr_tt_no;
	ptt_no_s->index = 6;
	md_symptom_info.push_back(ptt_dt_s);
	md_symptom_info.push_back(ptt_jcxtt_s);
	md_symptom_info.push_back(ptt_jqtt_s);
	md_symptom_info.push_back(ptt_zt_s);
	md_symptom_info.push_back(ptt_rt_s);
	md_symptom_info.push_back(ptt_no_s);

	//左侧疼痛单项
	symptom_info* pl_tt_dt_s = new symptom_info();
	symptom_info* pl_tt_jcxtt_s = new symptom_info();
	symptom_info* pl_tt_jqtt_s = new symptom_info();
	symptom_info* pl_tt_zt_s = new symptom_info();
	symptom_info* pl_tt_rt_s = new symptom_info();
	symptom_info* pl_tt_no_s = new symptom_info();
	//pl_tt_dt_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛钝痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_duntong", pl_tt_dt_s->v_names);
	pl_tt_dt_s->pleft = ui.ml_tt_dt;
	pl_tt_dt_s->pright = nullptr;
	pl_tt_dt_s->index = 61;
	//pl_tt_jcxtt_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_jcxtt", pl_tt_jcxtt_s->v_names);
	pl_tt_jcxtt_s->pleft = ui.ml_tt_jcxtt;
	pl_tt_jcxtt_s->pright = nullptr;
	pl_tt_jcxtt_s->index = 61;
	//pl_tt_jqtt_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛经期疼痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_jqtt", pl_tt_jqtt_s->v_names);
	pl_tt_jqtt_s->pleft = ui.ml_tt_jqtt;
	pl_tt_jqtt_s->pright = nullptr;
	pl_tt_jqtt_s->index = 61;
	//pl_tt_zt_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛胀痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_zhangtong", pl_tt_zt_s->v_names);
	pl_tt_zt_s->pleft = ui.ml_tt_zt;
	pl_tt_zt_s->pright = nullptr;
	pl_tt_zt_s->index = 61;
	//pl_tt_rt_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛锐痛"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_ruitong", pl_tt_rt_s->v_names);
	pl_tt_rt_s->pleft = ui.ml_tt_rt;
	pl_tt_rt_s->pright = nullptr;
	pl_tt_rt_s->index = 61;
	//pl_tt_no_s->v_names.push_back(QString::fromLocal8Bit("左侧疼痛否"));
	read_config("/ini/tengtong_config.ini", "l_tengtong_no", pl_tt_no_s->v_names);
	pl_tt_no_s->pleft = ui.ml_tt_no;
	pl_tt_no_s->pright = nullptr;
	pl_tt_no_s->index = 61;
	md_symptom_info.push_back(pl_tt_dt_s);
	md_symptom_info.push_back(pl_tt_jcxtt_s);
	md_symptom_info.push_back(pl_tt_jqtt_s);
	md_symptom_info.push_back(pl_tt_zt_s);
	md_symptom_info.push_back(pl_tt_rt_s);
	md_symptom_info.push_back(pl_tt_no_s);

	//右侧疼痛单项
	symptom_info* pr_tt_dt_s = new symptom_info();
	symptom_info* pr_tt_jcxtt_s = new symptom_info();
	symptom_info* pr_tt_jqtt_s = new symptom_info();
	symptom_info* pr_tt_zt_s = new symptom_info();
	symptom_info* pr_tt_rt_s = new symptom_info();
	symptom_info* pr_tt_no_s = new symptom_info();
	//pr_tt_dt_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛钝痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_duntong", pr_tt_dt_s->v_names);
	pr_tt_dt_s->pleft = nullptr;
	pr_tt_dt_s->pright = ui.mr_tt_dt;
	pr_tt_dt_s->index = 62;
	//pr_tt_jcxtt_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛经常性疼痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_jcxtt", pr_tt_jcxtt_s->v_names);
	pr_tt_jcxtt_s->pleft = nullptr;
	pr_tt_jcxtt_s->pright = ui.mr_tt_jcxtt;
	pr_tt_jcxtt_s->index = 62;
	//pr_tt_jqtt_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛经期疼痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_jqtt", pr_tt_jqtt_s->v_names);
	pr_tt_jqtt_s->pleft = nullptr;
	pr_tt_jqtt_s->pright = ui.mr_tt_jqtt;
	pr_tt_jqtt_s->index = 62;
	//pr_tt_zt_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛胀痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_zhangtong", pr_tt_zt_s->v_names);
	pr_tt_zt_s->pleft = nullptr;
	pr_tt_zt_s->pright = ui.mr_tt_zt;
	pr_tt_zt_s->index = 62;
	//pr_tt_rt_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛锐痛"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_ruitong", pr_tt_rt_s->v_names);
	pr_tt_rt_s->pleft = nullptr;
	pr_tt_rt_s->pright = ui.mr_tt_rt;
	pr_tt_rt_s->index = 62;
	//pr_tt_no_s->v_names.push_back(QString::fromLocal8Bit("右侧疼痛否"));
	read_config("/ini/tengtong_config.ini", "r_tengtong_no", pr_tt_no_s->v_names);
	pr_tt_no_s->pleft = nullptr;
	pr_tt_no_s->pright = ui.mr_tt_no;
	pr_tt_no_s->index = 62;
	md_symptom_info.push_back(pr_tt_dt_s);
	md_symptom_info.push_back(pr_tt_jcxtt_s);
	md_symptom_info.push_back(pr_tt_jqtt_s);
	md_symptom_info.push_back(pr_tt_zt_s);
	md_symptom_info.push_back(pr_tt_rt_s);
	md_symptom_info.push_back(pr_tt_no_s);
}

//乳房类型信息
void record64::init_rufang_type_info()
{
	//乳房类型
	symptom_info* prf_type_zm = new symptom_info();
	symptom_info* prf_type_zf = new symptom_info();
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("致密型"));  
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("致命型"));
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("致命性")); 
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("治民行"));
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("甄宓性")); 
	//prf_type_zm->v_names.push_back(QString::fromLocal8Bit("是命行")); 
	read_config("/ini/rufang_type_config.ini", "rufang_zmx", prf_type_zm->v_names);
	prf_type_zm->pleft = ui.m_rf_zmx;
	prf_type_zm->pright = nullptr;
	prf_type_zm->index = 13;
	//prf_type_zf->v_names.push_back(QString::fromLocal8Bit("脂肪型"));
	//prf_type_zf->v_names.push_back(QString::fromLocal8Bit("只方形")); 
	read_config("/ini/rufang_type_config.ini", "rufang_zfx", prf_type_zf->v_names);
	prf_type_zf->pleft = ui.m_rf_zfx;
	prf_type_zf->pright = nullptr;
	prf_type_zf->index = 13;
	v_breast_rflx.push_back(prf_type_zm);
	v_breast_rflx.push_back(prf_type_zf);
	breast_info* prflx = new breast_info();
	//prflx->v_names.push_back(QString::fromLocal8Bit("乳房类型")); 
	//prflx->v_names.push_back(QString::fromLocal8Bit("鲁丰类型"));
	//prflx->v_names.push_back(QString::fromLocal8Bit("主方类型"));
	//prflx->v_names.push_back(QString::fromLocal8Bit("汝芳类型")); 
	read_config("/ini/rufang_type_config.ini", "rufang_type", prflx->v_names);
	prflx->vinfo = v_breast_rflx;
	prflx->pdefault = prf_type_zm;
	//prflx->bleft = false;
	//prflx->bright = false;
	md_breast.push_back(prflx);

	symptom_info* prf_type_zm_s = new symptom_info();
	symptom_info* prf_type_zf_s = new symptom_info();
	//prf_type_zm_s->v_names.push_back(QString::fromLocal8Bit("乳房类型致密型"));
	//prf_type_zm_s->v_names.push_back(QString::fromLocal8Bit("乳房类型致命型")); 
	//prf_type_zm_s->v_names.push_back(QString::fromLocal8Bit("乳房类型甄宓型"));
	//prf_type_zm_s->v_names.push_back(QString::fromLocal8Bit("有方类型致密型")); 
	read_config("/ini/rufang_type_config.ini", "rufang_all_zmx", prf_type_zm_s->v_names);
	prf_type_zm_s->pleft = ui.m_rf_zmx;
	prf_type_zm_s->pright = nullptr;
	prf_type_zm_s->index = 13;
	//prf_type_zf_s->v_names.push_back(QString::fromLocal8Bit("乳房类型脂肪型"));
	read_config("/ini/rufang_type_config.ini", "rufang_all_zfx", prf_type_zf_s->v_names);
	prf_type_zf_s->pleft = ui.m_rf_zfx;
	prf_type_zf_s->pright = nullptr;
	prf_type_zf_s->index = 13;
	md_symptom_info.push_back(prf_type_zm_s);
	md_symptom_info.push_back(prf_type_zf_s);
}

//开始结束信息
void record64::init_start_end_info()
{
	read_config("/ini/start_end.ini", "start", v_start_info);
	read_config("/ini/start_end.ini", "end", v_end_info);
}

//初始化用于保存 界面上乳房各个部位信息的vector(索引，是否选中，QRadioButton指针)
void record64::init_breast_rt_info()
{
	for (auto it : v_breast_realtime_info)
	{
		if (it)
		{
			delete it;
			it = nullptr;
		}
	}
	v_breast_realtime_info.clear();

	realtime_info* prt_l = new realtime_info();
	realtime_info* prt_r = new realtime_info();
	realtime_info* ppf_l = new realtime_info();
	realtime_info* ppf_r = new realtime_info();
	realtime_info* pyy_l = new realtime_info();
	realtime_info* pyy_r = new realtime_info();
	realtime_info* pxt_l = new realtime_info();
	realtime_info* pxt_r = new realtime_info();
	realtime_info* pfr_l = new realtime_info();
	realtime_info* pfr_r = new realtime_info();
	realtime_info* ptt_l = new realtime_info();
	realtime_info* ptt_r = new realtime_info();
	realtime_info* prf_type = new realtime_info();

	prt_l->index = 11;
	prt_l->bchecked = false;
	prt_l->pdefault = ui.ml_rt_normal;
	prt_r->index = 12;
	prt_r->bchecked = false;
	prt_r->pdefault = ui.mr_rt_normal;

	ppf_l->index = 21;
	ppf_l->bchecked = false;
	ppf_l->pdefault = ui.ml_pf_normal;
	ppf_r->index = 22;
	ppf_r->bchecked = false;
	ppf_r->pdefault = ui.mr_pf_normal;

	pyy_l->index = 31;
	pyy_l->bchecked = false;
	pyy_l->pdefault = ui.ml_yy_no;
	pyy_r->index = 32;
	pyy_r->bchecked = false;
	pyy_r->pdefault = ui.mr_yy_no;

	pxt_l->index = 41;
	pxt_l->bchecked = false;
	pxt_l->pdefault = ui.ml_xt_normal;
	pxt_r->index = 42;
	pxt_r->bchecked = false;
	pxt_r->pdefault = ui.mr_xt_normal;

	pfr_l->index = 51;
	pfr_l->bchecked = false;
	pfr_l->pdefault = ui.ml_fr_no;
	pfr_r->index = 52;
	pfr_r->bchecked = false;
	pfr_r->pdefault = ui.mr_fr_no;

	ptt_l->index = 61;
	ptt_l->bchecked = false;
	ptt_l->pdefault = ui.ml_tt_no;
	ptt_r->index = 62;
	ptt_r->bchecked = false;
	ptt_r->pdefault = ui.mr_tt_no;

	prf_type->index = 13;
	prf_type->bchecked = false;
	prf_type->pdefault = ui.m_rf_zmx;

	v_breast_realtime_info.push_back(prt_l);
	v_breast_realtime_info.push_back(prt_r);
	v_breast_realtime_info.push_back(ppf_l);
	v_breast_realtime_info.push_back(ppf_r);
	v_breast_realtime_info.push_back(pyy_l);
	v_breast_realtime_info.push_back(pyy_r);
	v_breast_realtime_info.push_back(pxt_l);
	v_breast_realtime_info.push_back(pxt_r);
	v_breast_realtime_info.push_back(pfr_l);
	v_breast_realtime_info.push_back(pfr_r);
	v_breast_realtime_info.push_back(ptt_l);
	v_breast_realtime_info.push_back(ptt_r);
	v_breast_realtime_info.push_back(prf_type);
}

//设置v_breast_realtime_info 里面对应索引的 bchecked 为真
void record64::set_breast_checked(int index)
{
	if (index <= 6)
	{
		for (int i = 1; i <= 2; ++i)
		{
			QString sindex = QString::number(index);
			sindex += QString::number(i);
			int temp_index = sindex.toInt();
			for (auto it : v_breast_realtime_info)
			{
				if (it->index == temp_index)
				{
					it->bchecked = true;
					break;
				}	
			}
		}
	}
	else
	{
		for (auto it : v_breast_realtime_info)
		{
			if (it->index == index)
			{
				it->bchecked = true;
				break;
			}		
		}
	}
}

//识别结束后，把没有被描述过的 乳房部位设置为默认值
void record64::set_other_breast_info()
{
	for (auto it : v_breast_realtime_info)
	{
		if (false == it->bchecked)
			it->pdefault->setChecked(true);
	}
}

bool record64::compare_result(vector<QString> &vnames,QString sresult)
{
	for (auto it : vnames)
	{
		if (!it.compare(sresult))
			return true;
	}

	return false;
}

void record64::read_config(QString config_name, QString name, vector<QString>& v_values)
{
	Config config(QCoreApplication::applicationDirPath()+config_name);
	QString snum = name + "_num";
	int value_count = config.Get(name, snum).toInt();

	QString value_index = "";
	QString value;
	for (int i = 0; i < value_count; ++i)
	{
		value_index = name + "_"+QString::number(i+1);
		value = config.Get(name, value_index).toString();
		v_values.push_back(value.toUtf8());
	}
}