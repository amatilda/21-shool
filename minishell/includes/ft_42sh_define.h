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

# define PROG_42SH					"minishell"
# define LIMIT_LIST_42SH			0x15
# define BUFFER_READ_42SH			0x8
# define BUFFER_OUT_42SH			0x1000

# define AUTO_CMD_42SH				0x1

# define DSPBACK_AUTO_42SH			0x0
# define DSPBACK_AUTO_CLEAR_42SH	0x1
# define DSPBACK_AUTO_RAW_42SH		0x2

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

# define MSG_FOOR_42SH	WAR_PR_42SH": Process limit exceeded.\n"PRTF_RESET

# define MSG_EXE_DEFINE_42SH	WAR_PR_42SH": Permission denied: "PRTF_RESET

# define MSG_ENV_42SH WAR_PR_42SH": Environment Variables - None.\n"PRTF_RESET

# define MSG_SETENV_42SH			"Usage : setenv <NAME> <VALUE>\n"
# define MSG_SETENV_SPACE_42SH		"<VALUE> - should not be empty.\n"

# define MSG_UNSETENV_42SH			"Usage : unsetenv <NAME>\n"
# define MSG_UNSETENV_NOT_42SH	WAR_42SH"This environment - not: "PRTF_RESET

# define MSG_CD_42SH				"Usage : cd <PATH>\n"
# define MSG_CD_NOT_VALID_42SH		WAR_42SH"No such directory: "PRTF_RESET

# define MSG_TAB_LIMIT_42SH		"\n"PROG_42SH": do you wish to see all "
# define MSG_TAB_LIM_A_42SH		" possibilities? "
# define MSG_TAB_LIM_L_42SH	LEN_(MSG_TAB_LIMIT_42SH)+LEN_(MSG_TAB_LIM_A_42SH)-1

# define MSG_EXE_NOT_CMD_42SH	WAR_PR_42SH": command not found: "PRTF_RESET

# define KEY_UP_42SH 				0x415B1B
# define KEY_DOWN_42SH 				0x425B1B
# define KEY_RIGHT_42SH 			0x435B1B
# define KEY_LEFT_42SH 				0x445B1B
# define KEY_HOME_42SH 				0x485B1B
# define KEY_END_42SH 				0x465B1B
# define KEY_DELETE_42SH			0x7E335B1B
# define KEY_BACKSPACE_42SH			0x7F
# define KEY_TAB_42SH				0x9
# define KEY_ENTER_42SH				0xA

# define TAB_LIMIT_42SH				0x30

#endif
