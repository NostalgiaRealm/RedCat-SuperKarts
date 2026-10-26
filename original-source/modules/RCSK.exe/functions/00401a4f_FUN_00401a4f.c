/*
 * FUN_00401a4f at 00401a4f
 * undefined __cdecl FUN_00401a4f(UINT param_1, int param_2, int param_3)
 * Address ranges: 00401a4f-00401ae7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00401a4f(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_00408c4c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00408c48 = 1;
  DAT_00408c44 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0040a134 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0040a130 - 4), DAT_0040a134 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0040a134 <= puVar1);
    }
    FUN_00401ae8((undefined4 *)&DAT_00408018,(undefined4 *)&DAT_00408020);
  }
  FUN_00401ae8((undefined4 *)&DAT_00408024,(undefined4 *)&DAT_00408028);
  if (param_3 != 0) {
    return;
  }
  DAT_00408c4c = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}

