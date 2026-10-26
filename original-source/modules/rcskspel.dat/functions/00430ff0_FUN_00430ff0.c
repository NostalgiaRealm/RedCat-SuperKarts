/*
 * FUN_00430ff0 at 00430ff0
 * undefined FUN_00430ff0(void)
 * Address ranges: 00430ff0-004310ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430ff0(int param_1)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  FUN_004932e0(param_1);
  iVar1 = DAT_006a5c38 + *(int *)(iVar1 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
  param_1 = 0;
  FUN_00495fe0(*(undefined4 *)(iVar1 + 0x50),*(undefined4 *)(iVar1 + 0x54),
               *(undefined4 *)(iVar1 + 0x58),&param_1,&local_4,&local_8);
  FUN_00496290(*(undefined4 *)(iVar1 + 0x50),*(undefined4 *)(iVar1 + 0x54),
               *(undefined4 *)(iVar1 + 0x58),local_4,local_8);
  return;
}

