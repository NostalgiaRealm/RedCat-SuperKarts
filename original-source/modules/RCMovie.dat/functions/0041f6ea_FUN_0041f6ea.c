/*
 * FUN_0041f6ea at 0041f6ea
 * undefined __cdecl FUN_0041f6ea(UINT param_1, int param_2, int param_3)
 * Address ranges: 0041f6ea-0041f782
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041f6ea(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0043e308 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0043e304 = 1;
  DAT_0043e300 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0043f930 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0043f92c - 4), DAT_0043f930 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0043f930 <= puVar1);
    }
    FUN_0041f783((undefined4 *)&DAT_0042c01c,(undefined4 *)&DAT_0042c024);
  }
  FUN_0041f783((undefined4 *)&DAT_0042c028,(undefined4 *)&DAT_0042c030);
  if (param_3 != 0) {
    return;
  }
  DAT_0043e308 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}

