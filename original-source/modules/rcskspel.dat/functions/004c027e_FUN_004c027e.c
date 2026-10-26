/*
 * FUN_004c027e at 004c027e
 * undefined FUN_004c027e(void)
 * Address ranges: 004c027e-004c0316
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c027e(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_006b6730 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_006b672c = 1;
  DAT_006b6728 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_006b7dd4 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_006b7dd0 - 4), DAT_006b7dd4 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_006b7dd4 <= puVar1);
    }
    FUN_004c0317(&DAT_004dd600,&DAT_004dd608);
  }
  FUN_004c0317(&DAT_004dd60c,&DAT_004dd614);
  if (param_3 != 0) {
    return;
  }
  DAT_006b6730 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}

