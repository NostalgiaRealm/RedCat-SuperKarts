/*
 * FUN_004afee0 at 004afee0
 * undefined FUN_004afee0(void)
 * Address ranges: 004afee0-004aff5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004afee0(undefined4 param_1)

{
  int iVar1;
  CHAR local_190 [400];
  
  FUN_004bf568(local_190,param_1,&stack0x00000008);
  FUN_004afcc0(0,1);
  FUN_004afce0(s___d___s_004feb90,0,local_190);
  ShowWindow(DAT_006a64b4,6);
  iVar1 = FUN_004baf80();
  while (iVar1 != 0) {
    iVar1 = FUN_004baf80();
  }
  MessageBoxExA((HWND)0x0,local_190,&DAT_004feb88,0x10010,0);
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}

