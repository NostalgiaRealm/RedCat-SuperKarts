/*
 * FUN_0040d660 at 0040d660
 * undefined __cdecl FUN_0040d660(int * param_1, undefined1 * param_2)
 * Address ranges: 0040d660-0040d72e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040d660(int *param_1,undefined1 *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined2 uVar3;
  uint uVar4;
  
  DAT_0040e9d0._0_2_ = (short)param_1[0x1d04];
  uVar3 = CONCAT11(*param_2,*param_2);
  *(undefined2 *)((int)param_1 + 0x7426) = uVar3;
  *(undefined2 *)((int)param_1 + 0x7436) = uVar3;
  puVar2 = (uint *)((int)param_1 + *param_1 + 0x7468);
  for (uVar4 = (uint)param_1[1] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if ((short)DAT_0040e9d0 != (short)uVar1) {
      *(ushort *)((int)puVar2 + 2) = CONCAT11(param_2[uVar1 >> 8 & 0xff],param_2[uVar1 & 0xff]);
    }
    puVar2 = puVar2 + 1;
  }
  puVar2 = (uint *)((int)param_1 + *param_1 + param_1[1] + 0x7468);
  for (uVar4 = (uint)param_1[2] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if ((short)DAT_0040e9d0 != (short)uVar1) {
      *(ushort *)((int)puVar2 + 2) = CONCAT11(param_2[uVar1 >> 8 & 0xff],param_2[uVar1 & 0xff]);
    }
    puVar2 = puVar2 + 1;
  }
  puVar2 = (uint *)((int)param_1 + *param_1 + param_1[1] + param_1[2] + 0x7468);
  for (uVar4 = (uint)param_1[3] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    uVar1 = *puVar2;
    if (((short)DAT_0040e9d0 != (short)uVar1) && ((uVar1 & 3) == 3)) {
      *(undefined1 *)((int)puVar2 + 3) = param_2[uVar1 >> 8 & 0xff];
    }
    puVar2 = puVar2 + 1;
  }
  return;
}

