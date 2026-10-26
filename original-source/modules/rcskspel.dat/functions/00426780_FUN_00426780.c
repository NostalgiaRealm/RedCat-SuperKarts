/*
 * FUN_00426780 at 00426780
 * undefined FUN_00426780(void)
 * Address ranges: 00426780-004267fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426780(uint param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  
  param_1 = param_1 & 0x80000001;
  bVar3 = param_1 == 0;
  if ((int)param_1 < 0) {
    bVar3 = (param_1 - 1 | 0xfffffffe) == 0xffffffff;
  }
  *(undefined4 *)(param_2 + 0x18) = 0x3f500000;
  puVar1 = (undefined4 *)(param_2 + 0x1c);
  if (bVar3) {
    *puVar1 = 0x3de00000;
    *(undefined4 *)(param_2 + 0x38) = 0x3f7c0000;
    uVar2 = 0x3de00000;
  }
  else {
    *puVar1 = 0x3d900000;
    *(undefined4 *)(param_2 + 0x38) = 0x3f7c0000;
    uVar2 = 0x3d900000;
  }
  *(undefined4 *)(param_2 + 0x3c) = uVar2;
  *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_3 + 0x1c) = *puVar1;
  *(undefined4 *)(param_3 + 0x38) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_3 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  return;
}

