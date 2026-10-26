/*
 * FUN_0049f2e0 at 0049f2e0
 * undefined FUN_0049f2e0(void)
 * Address ranges: 0049f2e0-0049f33f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049f2e0(LPCSTR param_1,int param_2)

{
  int iVar1;
  int *unaff_retaddr;
  undefined4 uVar2;
  
  FUN_004afcc0(0,1);
  FUN_004afce0(&DAT_004fa9e4,param_1);
  ShowWindow(DAT_006a64b4,6);
  iVar1 = FUN_004baf80();
  while (iVar1 != 0) {
    iVar1 = FUN_004baf80();
  }
  MessageBoxExA((HWND)0x0,param_1,s_Assertion_failure_004fa9d0,0x10010,0);
  FUN_004afdd0();
  uVar2 = 0;
  FUN_004c025c(0);
  FUN_0049f2a0(unaff_retaddr != (int *)0x0,s__s___d__NULL_pointer_passed_to_C_004fc68c,
               s_D__work_rcracer_oursoundlib_soun_004fc6b8,0x9d,uVar2);
  if (*unaff_retaddr < (int)param_1) {
    *unaff_retaddr = (int)param_1;
  }
  if (param_2 < *unaff_retaddr) {
    *unaff_retaddr = param_2;
  }
  return;
}

