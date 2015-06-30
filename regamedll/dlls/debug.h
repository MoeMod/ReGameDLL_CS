/*
*
*   This program is free software; you can redistribute it and/or modify it
*   under the terms of the GNU General Public License as published by the
*   Free Software Foundation; either version 2 of the License, or (at
*   your option) any later version.
*
*   This program is distributed in the hope that it will be useful, but
*   WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*   General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software Foundation,
*   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*   In addition, as a special exception, the author gives permission to
*   link the code of this program with the Half-Life Game Engine ("HL
*   Engine") and Modified Game Libraries ("MODs") developed by Valve,
*   L.L.C ("Valve").  You must obey the GNU General Public License in all
*   respects for all of the code used other than the HL Engine and MODs
*   from Valve.  If you modify this file, you may extend this exception
*   to your version of the file, but you are not obligated to do so.  If
*   you do not wish to do so, delete this exception statement from your
*   version.
*
*/

#ifndef DEBUG_H
#define DEBUG_H
#ifdef _WIN32
#pragma once
#endif

const int NUM_LEVELS = 6;
const int DebugBufferSize = 1024;

typedef enum
{
	DEBUG_NONE = 0,
	DEBUG_BOT,
	DEBUG_CAREER,
	DEBUG_TUTOR,
	DEBUG_STATS,
	DEBUG_HOSTAGE,
	DEBUG_ALL = 0xFFFFFFFF,
} DebugOutputType;

struct DebugOutputLevel
{
	const char *name;
	DebugOutputType value;
};/* size: 8, cachelines: 1, members: 2 */

#ifdef HOOK_GAMEDLL

#define outputLevel (*poutputLevel)
#define theDebugOutputTypes (*ptheDebugOutputTypes)
#define theDebugBuffer (*ptheDebugBuffer)

#endif // HOOK_GAMEDLL

extern DebugOutputLevel outputLevel[NUM_LEVELS];
extern unsigned int theDebugOutputTypes;
extern char theDebugBuffer[DebugBufferSize];

NOXREF bool IsDeveloper(void);
NOBODY void UTIL_DPrintf(DebugOutputType outputType, char *pszMsg, ...);
void UTIL_DPrintf(char *pszMsg, ...);
NOXREF void PrintDebugFlags(void);

NOBODY void SetDebugFlag(const char *flagStr, bool state);
NOBODY void PrintDebugFlag(const char *flagStr);
NOBODY void UTIL_SetDprintfFlags(const char *flagStr);
NOBODY void UTIL_BotDPrintf(char *pszMsg, ...);
NOBODY void UTIL_CareerDPrintf(char *pszMsg, ...);
NOBODY void UTIL_TutorDPrintf(char *pszMsg, ...);
NOBODY void UTIL_StatsDPrintf(char *pszMsg, ...);
NOBODY void UTIL_HostageDPrintf(char *pszMsg, ...);

#ifdef HOOK_GAMEDLL

typedef void (*DPrintf_Flag)(DebugOutputType outputType, char *pszMsg, ...);
typedef void (*DPrintf_MSG)(char *pszMsg, ...);

#endif // HOOK_GAMEDLL

#endif // DEBUG_H
