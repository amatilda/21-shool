/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_DEFINE_H
# define FT_42SH_DEFINE_H

# include "pguitar/ft_42sh_pguitar_define.h"

# define PROG_42SH					"42sh"

# define LIMIT_LIST_42SH			0x16
# define BUFFER_READ_42SH			0x8
# define BUFFER_OUT_42SH			0x1000
# define BUFFER_ERR_42SH			0x100
# define BUFFER_LITTER_42SH			0x2

# define STATUS_OK_42SH				0x0
# define STATUS_FALTURE_42SH		0x1
# define STATUS_FD_CLOSE_42SH		0x2
# define STATUS_TEST_ERR_42SH		0x2
# define STATUS_DEFINED_CMD_42SH	0x7E
# define STATUS_NOT_FIN_CMD_42SH	0x7F
# define STATUS_JOBS_STOP_42SH		0x92
# define STATUS_REZERVED_42SH		-1

# define SHIELD_EXTERNALLY			0x1
# define SHIELD_INTERIOR			0x2

# define SCRIPT_MAX_SIZE_42SH		0x10000

# define LOCATION_STANDART_42SH		0x1
# define LOCATION_SCRIPT_42SH		0x2
# define LOCATION_FORK_42SH			0x4
# define LOCATION_NOT_DSP_ERR_42SH	0x8
# define LOCATION_NOT_SET_42SH		0x10

# define CRC32_DEPTH_42SH			0x1
# define CRC32_POLINOM_MIRROR_42SH	0x82F63B78
# define CRC32_START_MIRROR_42SH	0xFFFFFFFF

# define AUTO_TYPE_SET_42SH			0x0
# define AUTO_TYPE_FUN_42SH			0x1
# define AUTO_TYPE_EXE_42SH			0x2
# define AUTO_TYPE_ALIAS_42SH		0x4
# define AUTO_TYPE_RUN_42SH			0x8
# define AUTO_TYPE_SET_RUN_42SH		(AUTO_TYPE_SET_42SH | AUTO_TYPE_RUN_42SH)
# define AUTO_TYPE_HASH_42SH		0x10
# define AUTO_TYPE_ERROR_42SH		0x20

# define JOBS_STOP_42SH				0x1
# define JOBS_MSG_42SH				0x2
# define JOBS_SUSPEND_42SH			0x4

# define CD_LOGIC_42SH				0x1
# define CD_PHYSICAL_42SH			0x2
# define CD_VIEW_42SH				0x4
# define CD_CANON_42SH				0x8

# define HASH_NOT_42SH				0x0
# define HASH_ALL_42SH				0x1
# define HASH_ONLY_42SH				0x2

# define EXIT_ANYWAY_42SH			0x1

# define JOBS_MSG_PROC_42SH			0x1
# define JOBS_MSG_ID_42SH			0x2
# define JOBS_MSG_PLUS_42SH			0x4
# define JOBS_MSG_MINUS_42SH		0x8
# define JOBS_MSG_ID_PID_42SH		0x10
# define JOBS_MSG_ID_PID_ALL_42SH	0x20
# define JOBS_MSG_ID_PID_GRUP_42SH	0x40
# define JOBS_MSG_JOBS_42SH			0x80
# define JOBS_MSG_FG_42SH			0x100
# define JOBS_MSG_BG_42SH			0x200
# define JOBS_MSG_ID_RUN_42SH		0x400
# define JOBS_MSG_CONTINUED_42SH	0x800

# define PARSING_FALTURE_42SH		0xFF

# define PARSING_MODE_CMD_42SH			0x1
# define PARSING_MODE_ARG_42SH			0x2
# define PARSING_MODE_HRDC_42SH			0x8
# define PARSING_MODE_ERR_42SH			0x10

# define EXP_PATH_42SH				"PATH"
# define EXP_HOME_42SH				"HOME"
# define EXP_PWD_42SH				"PWD"
# define EXP_OLDPWD_42SH			"OLDPWD"
# define EXP_CDPATH_42SH			"CDPATH"
# define EXP_HOME_PATH_42SH			"/Users/"

# define EXP_LENG_42SH				0x1

# define EXP_TYPE_EVERIMENT_42SH	0x1
# define EXP_TYPE_LOCAL_42SH		0x2
# define EXP_TYPE_R_ONLY_42SH		0x4
# define EXP_TYPE_NUMBER_42SH		0x8
# define EXP_TYPE_CORECTION_42SH	0x10

# define PIPE_READ_42SH				0
# define PIPE_WRITE_42SH			1

# define PIPE_MAX_STANDART_FD_42SH	2
# define PIPE_MAX_SUPPORT_FD_42SH	9

# define PIPE_CLOSE_42SH		0x1
# define PIPE_AND_42SH			0x2
# define PIPE_42SH				0x4
# define PIPE_LEFT_42SH			0x8
# define PIPE_LEFT2_42SH		(0x10 | PIPE_LEFT_42SH)
# define PIPE_RIGHT_42SH		0x20
# define PIPE_RIGHT2_42SH		(0x40 | PIPE_RIGHT_42SH)
# define PIPE_ADD_ERR_42SH		0x80
# define PIPE_REPLASE_42SH		0x100

# define PIPE_FIRST_42SH		PIPE_CLOSE_42SH
# define PIPE_CENTRAL_42SH		PIPE_AND_42SH
# define PIPE_LAST_42SH			PIPE_42SH

# define CRIT_42SH				PRTF_RED
# define CRIT_PR_42SH			CRIT_42SH PROG_42SH
# define WAR_42SH				PRTF_RED
# define WAR_PR_42SH			WAR_42SH PROG_42SH

# define E_CODE_42SH		0
# define E_MEM_CODE_42SH	1
# define E_MEM_TXT_42SH		": Not enough space.\n"
# define E_MEM_42SH			CRIT_PR_42SH E_MEM_TXT_42SH PRTF_RESET
# define E_READ_CODE_42SH	2
# define E_READ_TXT_42SH	": The error read attempt on a socket.\n"
# define E_READ_42SH		CRIT_PR_42SH E_READ_TXT_42SH PRTF_RESET
# define E_EXE_CODE_42SH	3
# define E_EXE_TXT_42SH		": Could not start file for execution.\n"
# define E_EXE_42SH			CRIT_PR_42SH E_EXE_TXT_42SH PRTF_RESET
# define E_PIPE_CODE_42SH	4
# define E_PIPE_TXT_42SH	": Could not start pipe.\n"
# define E_PIPE_42SH		CRIT_PR_42SH E_PIPE_TXT_42SH PRTF_RESET
# define E_CD_CODE_42SH		5
# define E_CD_TXT_42SH		": Failed to change directory.\n"
# define E_CD_42SH		CRIT_PR_42SH E_CD_TXT_42SH PRTF_RESET
# define E_IOTL_CODE_42SH	6
# define E_IOTL_TXT_42SH	": Failed to iotl.\n"
# define E_IOTL_42SH		CRIT_PR_42SH E_IOTL_TXT_42SH PRTF_RESET
# define E_DUP_CODE_42SH	7
# define E_DUP_TXT_42SH	": Failed to dup.\n"
# define E_DUP_42SH		CRIT_PR_42SH E_DUP_TXT_42SH PRTF_RESET

# define E_FOOR_CODE_42SH	54
# define E_CANNON_CODE_42SH	55
# define E_CANON_TXT_42SH	": Error non-canonical mode of operation.\n"
# define E_CANON_42SH		CRIT_PR_42SH E_CANON_TXT_42SH PRTF_RESET
# define E_TERM_42SH		CRIT_PR_42SH": Not terminal\n"PRTF_RESET

# define MSG_42SH					"$> "
# define MSG_SP_42SH				"   "
# define PRE_MSG_42SH				PRTF_BOLT MSG_42SH PRTF_RESET
# define PRE_MSG_COUNT_42SH			LEN_(MSG_42SH)
# define PRE_MSG_LITTER_42SH		LEN_(MSG_42SH)
# define MSG_DQUOTE_42SH			"dquote> "
# define PRE_MSG_DQUOTE_42SH		PRTF_BOLT MSG_DQUOTE_42SH PRTF_RESET
# define PRE_MSG_DQUOTE_LITTER_42SH	LEN_(MSG_DQUOTE_42SH)
# define MSG_QUOTE_42SH				"quote> "
# define PRE_MSG_QUOTE_42SH			PRTF_BOLT MSG_QUOTE_42SH PRTF_RESET
# define PRE_MSG_QUOTE_LITTER_42SH	LEN_(MSG_QUOTE_42SH)
# define MSG_HEREDOC_42SH			"heredoc> "
# define PRE_MSG_HEREDOC_42SH		PRTF_BOLT MSG_HEREDOC_42SH PRTF_RESET
# define PRE_MSG_HEREDOC_LITTER_42SH	LEN_(MSG_HEREDOC_42SH)
# define MSG_SUB_42SH				"sub> "
# define PRE_MSG_SUB_42SH			PRTF_BOLT MSG_SUB_42SH PRTF_RESET
# define PRE_MSG_SUB_LITTER_42SH	LEN_(MSG_SUB_42SH)
# define MSG_CMD_42SH				"cmd> "
# define PRE_MSG_CMD_42SH			PRTF_BOLT MSG_CMD_42SH PRTF_RESET
# define PRE_MSG_CMD_LITTER_42SH	LEN_(MSG_CMD_42SH)

# define MSG_JOBS_PROC_42SH			PROG_42SH": "
# define MSG_JOBS_CONTINUED_42SH	"continued             : "
# define MSG_JOBS_DONE_42SH			"done                  : "
# define MSG_JOBS_RUN_42SH			"runing                : "
# define MSG_JOBS_EXIT_42SH			"exit               "
# define MSG_JOBS_EXIT_ADD_42SH		": "
# define MSG_JOBS_NULL_42SH			"user defined signal   : "
# define MSG_JOBS_HUP_42SH			"hangup                : "
# define MSG_JOBS_INT_42SH			"interrupt             : "
# define MSG_JOBS_QUIT_42SH			"quit                  : "
# define MSG_JOBS_ILL_42SH			"illegal instruction   : "
# define MSG_JOBS_TRAP_42SH			"trace trap            : "
# define MSG_JOBS_ABRT_42SH			"abort                 : "
# define MSG_JOBS_EMT_42SH			"EMT instruction       : "
# define MSG_JOBS_FPE_42SH			"floating exception    : "
# define MSG_JOBS_KILL_42SH			"killed                : "
# define MSG_JOBS_BUS_42SH			"bus error             : "
# define MSG_JOBS_SEGV_42SH			"segmentation fault    : "
# define MSG_JOBS_SYS_42SH			"invalid system call   : "
# define MSG_JOBS_PIPE_42SH			"broken pipe           : "
# define MSG_JOBS_ALRM_42SH			"alarm                 : "
# define MSG_JOBS_TERM_42SH			"terminated            : "
# define MSG_JOBS_GURD_42SH			"urgent condition      : "
# define MSG_JOBS_STOP_42SH			"suspended (signal)    : "
# define MSG_JOBS_STR_42SH			"suspended             : "
# define MSG_JOBS_CONT_42SH			"continue after stop   : "
# define MSG_JOBS_CHLD_42SH			"child status changed  : "
# define MSG_JOBS_TTIN_42SH			"suspended (tty input) : "
# define MSG_JOBS_TTON_42SH			"suspended (tty output): "
# define MSG_JOBS_GIO_42SH			"I/O is possible       : "
# define MSG_JOBS_XCPU_42SH			"cpu limit exceeded    : "
# define MSG_JOBS_XFSZ_42SH			"file size limit       : "
# define MSG_JOBS_TALR_42SH			"virtual time alarm    : "
# define MSG_JOBS_PROF_42SH			"profile signal        : "
# define MSG_JOBS_WINC_42SH			"window size change    : "
# define MSG_JOBS_INFO_42SH			"status from keyboard  : "
# define MSG_JOBS_USR1_42SH			"user defined signal 1 : "
# define MSG_JOBS_USR2_42SH			"user defined signal 2 : "

# define MSG_SH_TEST_42SH			"*.sh"
# define MSG_SH_TEST_TYPE_42SH		"*/42sh"
# define MSG_SH_DEFINED_42SH		": script permission denied."
# define MSG_SH_OPEN_FALLED_42SH	": script falled open."
# define MSG_SH_INVALID_SIZE_42SH	": script invalid size."
# define MSG_SH_INVALID_MEMORY_42SH	": script not enough space."
# define MSG_SH_INVALID_READ_42SH	": script invalid read."
# define MSG_SH_UNKNOWN_42SH		": script unknown."

# define MSG_STOP_42SH		PROG_42SH": can't set tty pgrp: interrupt\n"

# define MSG_EXP_QUEST_ERR_42SH	WAR_42SH": "PRTF_RESET
# define MSG_EXP_QUEST_NOT_SET_42SH	WAR_42SH" :parameter not set "PRTF_RESET

# define MSG_BAD_OPTION_42SH	WAR_PR_42SH": bad option:"PRTF_RESET" -"

# define MSG_FOOR_42SH	WAR_PR_42SH": process limit exceeded."PRTF_RESET

# define MSG_EXE_DEFINE_42SH	": permission denied: "
# define MSG_EXE_NOT_CMD_42SH	": command not found: "
# define MSG_EXE_NOT_42SH 		": no such file or directory: "
# define MSG_IS_DIR_42SH 		": is a directory: "
# define MSG_PIPE_EQV_42SH		": file mode mismatch on fd: "
# define MSG_PIPE_MUL_FD_42SH	": multio failed, bad file descriptor fd: "
# define MSG_PIPE_BAD_FD_42SH	": bad file descriptor: "

# define MSG_PIPE_NOT_N_42SH	PRTF_INVERT"%\n"PRTF_RESET

# define MSG_EXPR_42SH		"export"
# define MSG_EXPR_VIEW_42SH	"export "
# define MSG_EXPR_SET_VIEW_42SH	"set "
# define MSG_EXPR_NONE_TXT_42SH MSG_EXPR_42SH": Environment Variables - None."
# define MSG_EXPR_NONE_42SH	WAR_42SH MSG_EXPR_NONE_TXT_42SH PRTF_RESET
# define MSG_EXPR_NOT_V_TXT_42SH MSG_EXPR_42SH": not valid in this context: "
# define MSG_EXPR_NOT_V_42SH	WAR_42SH MSG_EXPR_NOT_V_TXT_42SH PRTF_RESET
# define MSG_EXPR_NOT_FIND_TXT_42SH MSG_EXPR_42SH": no such variable: "
# define MSG_EXPR_NOT_FIND_42SH	WAR_42SH MSG_EXPR_NOT_FIND_TXT_42SH PRTF_RESET

# define MSG_EXP_SUB_BAD_42SH	": bad substitution: "
# define MSG_SINTAX_ERROR_42SH	": parse error near: "
# define MSG_CLOSING_ERROR_42SH	": closing brace expected"

# define MSG_JOBS_42SH		"jobs"
# define MSG_JOBS_NOT_TXT_42SH MSG_JOBS_42SH": job not found: "
# define MSG_JOBS_NOT_42SH	WAR_42SH MSG_JOBS_NOT_TXT_42SH PRTF_RESET
# define MSG_JOBS_NOT_CUR_TXT_42SH MSG_JOBS_42SH": no current job"
# define MSG_JOBS_NOT_CUR_42SH	WAR_42SH MSG_JOBS_NOT_CUR_TXT_42SH PRTF_RESET
# define MSG_JOBS_NOT_PREV_TXT_42SH MSG_JOBS_42SH": no previous job"
# define MSG_JOBS_NOT_PREV_42SH	WAR_42SH MSG_JOBS_NOT_PREV_TXT_42SH PRTF_RESET

# define MSG_JOBS_QUEST_42SH PROG_42SH": you have suspended jobs, exit?(y/n) \x7"
# define MSG_JOBS_QUEST_LEN_42SH LEN_(MSG_JOBS_QUEST_42SH) - 1

# define MSG_FG_42SH		"fg"
# define MSG_FG_NOT_CONT_TXT_42SH MSG_FG_42SH": no job control in this shell."
# define MSG_FG_NOT_CONT_42SH	WAR_42SH MSG_FG_NOT_CONT_TXT_42SH PRTF_RESET

# define MSG_CD_42SH		"cd"
# define MSG_CD_TOO_ARG_TXT_42SH MSG_CD_42SH": too many arguments"
# define MSG_CD_TOO_ARG_42SH	WAR_42SH MSG_CD_TOO_ARG_TXT_42SH PRTF_RESET
# define MSG_CD_CHDIR_TXT_42SH MSG_CD_42SH": failed to change directory"
# define MSG_CD_CHDIR_42SH	WAR_42SH MSG_CD_CHDIR_TXT_42SH PRTF_RESET
# define MSG_CD_NOT_VALID_TXT_42SH MSG_CD_42SH": no such directory: "
# define MSG_CD_NOT_VALID_42SH	WAR_42SH MSG_CD_NOT_VALID_TXT_42SH PRTF_RESET

# define MSG_TEST_42SH			"test"
# define MSG_TEST_TOO_ARG_TXT_42SH MSG_TEST_42SH": too many arguments"
# define MSG_TEST_TOO_ARG_42SH	WAR_42SH MSG_TEST_TOO_ARG_TXT_42SH PRTF_RESET
# define MSG_TEST_UNK_COND_TXT_42SH MSG_TEST_42SH": unknown condition: "
# define MSG_TEST_UNK_COND_42SH	WAR_42SH MSG_TEST_UNK_COND_TXT_42SH PRTF_RESET
# define MSG_TEST_COND_TXT_42SH	MSG_TEST_42SH": condition expected: "
# define MSG_TEST_COND_42SH	WAR_42SH MSG_TEST_COND_TXT_42SH PRTF_RESET
# define MSG_TEST_INT_TXT_42SH	MSG_TEST_42SH": integer expression expected: "
# define MSG_TEST_INT_42SH	WAR_42SH MSG_TEST_INT_TXT_42SH PRTF_RESET

# define MSG_HASH_42SH		"hash"
# define MSG_HASH_PRE_42SH	"hits       command\n"
# define HASH_HITS_LEN_42SH	LEN_(MSG_HASH_PRE_42SH) - LEN_("command\n")

# define MSG_HASH_TOO_ARG_TXT_42SH MSG_HASH_42SH": too many arguments"
# define MSG_HASH_TOO_ARG_42SH	WAR_42SH MSG_HASH_TOO_ARG_TXT_42SH PRTF_RESET
# define MSG_HASH_NOT_FIND_TXT_42SH MSG_HASH_42SH": no such command:"
# define MSG_HASH_NOT_FIND_42SH	WAR_42SH MSG_HASH_NOT_FIND_TXT_42SH PRTF_RESET

# define MSG_BG_42SH		"bg"
# define MSG_BG_NOT_CONT_TXT_42SH MSG_BG_42SH": no job control in this shell."
# define MSG_BG_NOT_CONT_42SH	WAR_42SH MSG_BG_NOT_CONT_TXT_42SH PRTF_RESET
# define MSG_BG_ALREDY_TXT_42SH MSG_BG_42SH": job already in background"
# define MSG_BG_ALREDY_42SH	WAR_42SH MSG_BG_ALREDY_TXT_42SH PRTF_RESET

# define MSG_EXIT_42SH		"exit"
# define MSG_EXIT_TOO_TXT_42SH	MSG_EXIT_42SH": too many arguments"
# define MSG_EXIT_TOO_42SH	WAR_42SH MSG_EXIT_TOO_TXT_42SH PRTF_RESET
# define MSG_EXIT_NUM_TXT_42SH	MSG_EXIT_42SH": numeric argument required"
# define MSG_EXIT_NUM_42SH	WAR_42SH MSG_EXIT_NUM_TXT_42SH PRTF_RESET


# define MSG_TYPE_42SH			"type"
# define MSG_TYPE_NOT_42SH		" not found"
# define MSG_TYPE_FUN_42SH		" is a shell builtin"
# define MSG_TYPE_EXE_42SH		" is "
# define MSG_TYPE_ALIAS_42SH	" is an alias for "

# define MSG_SET_42SH		"set"
# define MSG_SET_NONE_TXT_42SH MSG_SET_42SH": Environment Variables - None."
# define MSG_SET_NONE_42SH	WAR_42SH MSG_SET_NONE_TXT_42SH PRTF_RESET

# define MSG_UNSET_42SH		"unset"
# define MSG_UNSET_R_ONLY_TXT_42SH MSG_UNSET_42SH": read-only variable: "
# define MSG_UNSET_R_ONLY_42SH	WAR_42SH MSG_UNSET_R_ONLY_TXT_42SH PRTF_RESET
# define MSG_UNSET_NOT_ARG_TXT_42SH MSG_UNSET_42SH": not enough arguments"
# define MSG_UNSET_NOT_ARG_42SH	WAR_42SH MSG_UNSET_NOT_ARG_TXT_42SH PRTF_RESET

# define MSG_TAB_LIMIT_42SH		"\n""do you wish to see all "
# define MSG_TAB_LIM_A_42SH		" possibilities? "
# define MSG_TAB_LIM_L_42SH	LEN_(MSG_TAB_LIMIT_42SH)+LEN_(MSG_TAB_LIM_A_42SH)-1

# define STR_HOME_PATH			"/"

# define KEY_UP_42SH 				0x415B1B
# define KEY_DOWN_42SH 				0x425B1B
# define KEY_RIGHT_42SH 			0x435B1B
# define KEY_LEFT_42SH 				0x445B1B
# define KEY_HOME_42SH 				0x1
# define KEY_END_42SH 				0x5
# define KEY_HOME_FULL_42SH 		0x485B1B
# define KEY_END_FULL_42SH 			0x465B1B
# define KEY_DELETE_42SH			0x7E335B1B
# define KEY_BACKSPACE_42SH			0x7F
# define KEY_TAB_42SH				0x9
# define KEY_ENTER_42SH				0xA
# define KEY_EOF_42SH				0x4
# define KEY_CLEAR_42SH				0xC
# define KEY_WORD_LEFT_42SH			0x2
# define KEY_WORD_RIGHT_42SH		0x6
# define KEY_SELECT_LEFT_42SH		0x44323B315B1B
# define KEY_SELECT_RIGHT_42SH		0x43323B315B1B
# define KEY_STR_DELETE_42SH		0x15
# define KEY_STR_COPY_42SH			0xB
# define KEY_STR_CUT_42SH			0x18
# define KEY_STR_PASTE_42SH			0x10
# define KEY_INT_42SH				0x3

# define TAB_LIMIT_42SH				0x30

#endif
