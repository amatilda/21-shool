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

# define PROG_42SH					"21sh"

# define PROG_42SH					"21sh"
# define LIMIT_LIST_42SH			0x16
# define BUFFER_READ_42SH			0x100
# define BUFFER_OUT_42SH			0x1000
# define BUFFER_ERR_42SH			0x100
# define BUFFER_LITTER_42SH			0x2

# define AUTO_CMD_42SH				0x1

# define AUTO_TYPE_FUN				0x0
# define AUTO_TYPE_EXE				0x1

# define PARSING_SUCCESS			0x0
# define PARSING_STOP				0xFE
# define PARSING_FALTURE			0xFF

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
# define PIPE_CLOSE_FD_42SH		0x100

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

# define E_CANON_TXT_42SH	": Error non-canonical mode of operation.\n"
# define E_CANON_42SH		CRIT_PR_42SH E_CANON_TXT_42SH PRTF_RESET
# define E_TERM_42SH		CRIT_PR_42SH": Not terminal\n"PRTF_RESET

# define ENV_PATH_42SH				"PATH"
# define ENV_HOME_42SH				"HOME"

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

# define MSG_FOOR_42SH	WAR_PR_42SH": Process limit exceeded."PRTF_RESET

# define MSG_EXE_DEFINE_42SH	WAR_PR_42SH": Permission denied: "PRTF_RESET

# define MSG_PIPE_NUMBER_42SH	WAR_PR_42SH": file number expected."PRTF_RESET
# define MSG_PIPE_BAD_FD_TXT_42SH	": bad file descriptor: "
# define MSG_PIPE_BAD_FD_42SH	WAR_PR_42SH MSG_PIPE_BAD_FD_TXT_42SH PRTF_RESET
# define MSG_PIPE_EQV_42SH	WAR_PR_42SH": file mode mismatch on fd: "PRTF_RESET
# define MSG_PIPE_NOT_N_42SH	PRTF_INVERT"%\n"PRTF_RESET

# define MSG_ENV_42SH WAR_PR_42SH": Environment Variables - None."PRTF_RESET

# define MSG_SINTAX_ERROR_42SH		WAR_PR_42SH": parse error near: "PRTF_RESET

# define MSG_SETENV_42SH			"Usage : setenv <NAME> <VALUE>"
# define MSG_SETENV_SPACE_42SH		"<VALUE> - should not be empty."

# define MSG_UNSETENV_42SH			"Usage : unsetenv <NAME>"
# define MSG_UNSETENV_NOT_42SH	WAR_42SH"This environment - not: "PRTF_RESET

# define MSG_CD_42SH				"Usage : cd <PATH>"
# define MSG_CD_NOT_VALID_42SH		WAR_42SH"No such directory: "PRTF_RESET

# define MSG_TAB_LIMIT_42SH		"\n"PROG_42SH": do you wish to see all "
# define MSG_TAB_LIM_A_42SH		" possibilities? "
# define MSG_TAB_LIM_L_42SH	LEN_(MSG_TAB_LIMIT_42SH)+LEN_(MSG_TAB_LIM_A_42SH)-1

# define MSG_EXE_NOT_CMD_42SH	WAR_PR_42SH": command not found: "PRTF_RESET
# define MSG_EXE_NOT_42SH WAR_PR_42SH": no such file or directory: "PRTF_RESET

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

# define TAB_LIMIT_42SH				0x30

#endif
