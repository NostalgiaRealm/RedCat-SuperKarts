/*
 * FUN_00448b00 at 00448b00
 * undefined FUN_00448b00(void)
 * Address ranges: 00448b00-00448bc2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448b00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_004a6200(s_C_TREIN_004efd44);
  iVar2 = FUN_0048fb60(0,0,0,0,0,0,uVar1,0,0,0,0,0);
  FUN_0043b760(iVar2,s_TRAIN_004efd4c);
  *(undefined4 *)(iVar2 * 0xd0 + 0x44 + DAT_0067ee20) = 0;
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar2;
  return;
}

