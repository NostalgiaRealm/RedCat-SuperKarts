/*
 * FUN_004afce0 at 004afce0
 * undefined FUN_004afce0(void)
 * Address ranges: 004afce0-004afd6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004afce0(undefined4 param_1)

{
  int iVar1;
  CHAR local_400 [1023];
  undefined1 local_1;
  
  if (DAT_006a64f8 == 1) {
    if (DAT_006a64fc == 0) {
      iVar1 = FUN_004bf445(s_debug_txt_004feadc,&DAT_004feae8);
      if (iVar1 != 0) {
        local_1 = 0;
        FUN_004bf8e0(local_400,0x3ff,param_1,&stack0x00000008);
        FUN_004bf8ae(iVar1,local_400);
        FUN_004bf2c5(iVar1);
      }
    }
    else if (DAT_006a64fc == 1) {
      OutputDebugStringA(local_400);
      return;
    }
  }
  return;
}

