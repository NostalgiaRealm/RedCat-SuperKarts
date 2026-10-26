/*
 * FUN_00444650 at 00444650
 * undefined __register FUN_00444650(int * param_1, int param_2)
 * Address ranges: 00444650-004446a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444650(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  iVar2 = DAT_0047d7a8;
  if (*(char *)(DAT_0047d7a8 + 0x20) == '\0') {
    *(undefined1 *)(DAT_0047d7a8 + 0x20) = 1;
    iVar2 = FUN_004498e8(DAT_0047d7a8,0x68);
  }
  bVar1 = FUN_00429770(CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(param_2 + 4)));
  *(byte *)(param_2 + 4) = bVar1;
  FUN_00403088(param_1,param_2,extraout_ECX);
  if (*(int *)(param_2 + 0xc) == 0) {
    (**(code **)(*param_1 + -0x10))(param_1,param_2);
  }
  return;
}

