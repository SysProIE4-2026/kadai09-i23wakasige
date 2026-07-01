/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

int main(int argc,char *argv[],char *envp[]) {
  int i=1;
  while ((putenv(argv[i])==0) && (i<=argc)) {
    putenv(argv[i]);
    i++;
  }
  if (i>=argc) {
    execvp("env",envp);
  } else {
    execvp(argv[i],&argv[i]);
  }
  
}

/* 実行例

% ./myenv LC_TIME=ja.JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 yoshitaka  staff     132 Jun 29 21:32 Makefile
-rw-r--r--  1 yoshitaka  staff    1268 Jun 29 21:32 README.md
-rw-r--r--  1 yoshitaka  staff  139098 Jun 29 21:32 README.pdf
-rwxr-xr-x  1 yoshitaka  staff   33608 Jun 30 20:09 myenv
-rw-r--r--  1 yoshitaka  staff     409 Jun 30 20:15 myenv.c
-rwxr-xr-x  1 yoshitaka  staff     216 Jun 29 21:32 myputenv.c
-rw-r--r--  1 yoshitaka  staff      93 Jun 29 21:32 myputenv.h

% ./myenv LC_TIME=ja.JP.UTF-8 TZ=Cuba      
OSLogRateLimit=64
MallocNanoZone=0
USER=yoshitaka
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/opt/openjdk/bin:/usr/local/bin:/System/Cryptexes/
App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/
com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/
var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/
var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
appleinternal/bin:/opt/pmk/env/global/bin:/opt/homebrew/bin:/opt/
homebrew/opt/openjdk/bin
LOGNAME=yoshitaka
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.jr9RVAZ9UQ/Listeners
HOME=/Users/yoshitaka
SHELL=/bin/zsh
TMPDIR=/var/folders/kk/h22p125d4mb95d15l7qgw3tc0000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
SHLVL=1
PWD=/Users/yoshitaka/SysPro/kadai09-i23wakasige
OLDPWD=/Users/yoshitaka/SysPro/kadai09-i23wakasige
LANG=C.UTF-8
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.120.0
COLORTERM=truecolor
VSCODE_JDWP_ADAPTER_ENDPOINTS=/Users/yoshitaka/.vscode/extensions/
vscjava.vscode-java-debug-0.59.0/.noConfigDebugAdapterEndpoints/
endpoint-942c1997421ed9ae.txt
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/
app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/
Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/
Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/kk/h22p125d4mb95d15l7qgw3tc0000gn/
T/vscode-git-f558c4ac5d.sock
VSCODE_NONCE=031dcdd4-c22f-4877-a449-1f01334c4337
TERM=xterm-256color
_=/Users/yoshitaka/SysPro/kadai09-i23wakasige/./myenv
LC_TIME=ja.JP.UTF-8
TZ=Cuba

% ./myenv                             
OSLogRateLimit=64
MallocNanoZone=0
USER=yoshitaka
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/opt/openjdk/bin:/usr/local/bin:/System/Cryptexes/
App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/
codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/
codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/
codex.system/bootstrap/usr/appleinternal/bin:/opt/pmk/env/global/bin:/
opt/homebrew/bin:/opt/homebrew/opt/openjdk/bin
LOGNAME=yoshitaka
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.jr9RVAZ9UQ/Listeners
HOME=/Users/yoshitaka
SHELL=/bin/zsh
TMPDIR=/var/folders/kk/h22p125d4mb95d15l7qgw3tc0000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x1:0xE
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
SHLVL=1
PWD=/Users/yoshitaka/SysPro/kadai09-i23wakasige
OLDPWD=/Users/yoshitaka/SysPro/kadai09-i23wakasige
LANG=C.UTF-8
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.120.0
COLORTERM=truecolor
VSCODE_JDWP_ADAPTER_ENDPOINTS=/Users/yoshitaka/.vscode/extensions/
vscjava.vscode-java-debug-0.59.0/.noConfigDebugAdapterEndpoints/
endpoint-942c1997421ed9ae.txt
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/
app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/
Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/
Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/kk/h22p125d4mb95d15l7qgw3tc0000gn/
T/vscode-git-f558c4ac5d.sock
VSCODE_NONCE=031dcdd4-c22f-4877-a449-1f01334c4337
TERM=xterm-256color
_=/Users/yoshitaka/SysPro/kadai09-i23wakasige/./myenv

*/
