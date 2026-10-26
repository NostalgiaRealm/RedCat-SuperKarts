/*
 * FUN_00405898 at 00405898
 * undefined * __register FUN_00405898(undefined * param_1, undefined1 * param_2, int param_3)
 * Address ranges: 00405898-00405902
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_00405898(undefined *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  if ((*(int *)(param_1 + 4) == 0xd7b2) ||
     ((param_1 == &DAT_0047d21c && (FUN_0040588a(&DAT_0047d21c), iRam0047d220 == 0xd7b2)))) {
    do {
      iVar1 = *(int *)(param_1 + 0xc);
      iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
      if (param_3 < iVar2) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
        puVar3 = (undefined1 *)(*(int *)(param_1 + 0x14) + iVar1);
        for (; param_3 != 0; param_3 = param_3 + -1) {
          *puVar3 = *param_2;
          param_2 = param_2 + (uint)bVar4 * -2 + 1;
          puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
        }
        return param_1;
      }
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar2;
      param_3 = param_3 - iVar2;
      puVar3 = (undefined1 *)(*(int *)(param_1 + 0x14) + iVar1);
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_2;
        param_2 = param_2 + (uint)bVar4 * -2 + 1;
        puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
      }
      iVar1 = (**(code **)(param_1 + 0x1c))();
    } while (iVar1 == 0);
    FUN_00402804(iVar1);
  }
  else {
    param_1 = (undefined *)FUN_00402804(0x69);
  }
  return param_1;
}

