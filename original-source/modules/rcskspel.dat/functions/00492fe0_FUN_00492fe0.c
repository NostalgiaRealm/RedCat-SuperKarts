/*
 * FUN_00492fe0 at 00492fe0
 * undefined FUN_00492fe0(void)
 * Address ranges: 00492fe0-0049306f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00492fe0(int param_1,undefined4 param_2)

{
  int iVar1;
  CHAR local_190 [400];
  
  if (param_1 == 0) {
    FUN_004bf568(local_190,param_2,&stack0x0000000c);
    FUN_004afcc0(0,1);
    FUN_004afce0(&DAT_004fa9e4,local_190);
    ShowWindow(DAT_006a64b4,6);
    iVar1 = FUN_004baf80();
    while (iVar1 != 0) {
      iVar1 = FUN_004baf80();
    }
    MessageBoxExA((HWND)0x0,local_190,s_Assertion_failure_004fa9d0,0x10010,0);
    FUN_004afdd0();
    FUN_004c025c(0);
  }
  return;
}

