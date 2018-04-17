#ifndef __STUDENT__H
#define __STUDENT__H

#define USR_NAME_LEN 20
#define USR_PWD_LEN 20

typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE usr_role;
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;

typedef struct usr_infor_tag
{
	int usr_id;
	char usr_name[USR_NAME_LEN];
	int usr_coursr_id;
	double usr_course_score;
	struct usr_info_tag *pNext_Usr_Infor;
}USR_INFOR, *pUSR_INFOR;

void ststem_init(const char *config_file_name, pUSR_ACCOUNT *pUsr_Account, pUSR_INFOR *pUsr_Infor);
//根据输入用户名和密码检查是否合法并确认当前账号的权限
USR_ROLE role_confirm(pUSR_ACCONT pUsr_Account, USR_ACCOUNT_UNM usr_account_num);
//显示系统菜单 返回当前用户所选择的菜单
#endif //__STUDENT__H
