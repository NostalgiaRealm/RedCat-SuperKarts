/*
 * FUN_00405903 at 00405903
 * undefined * __register FUN_00405903(undefined * param_1, int param_2)
 * Address ranges: 00405903-0040593b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_00405903(undefined *param_1,int param_2)

{
  int iVar1;
  LPVOID pvVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  while (0x40 < param_2) {
    param_2 = param_2 + -0x40;
    FUN_00405898(param_1,&DAT_0047b06c,0x40);
    pvVar2 = FUN_00406144();
    if (*(int *)((int)pvVar2 + 4) != 0) {
      return param_1;
    }
  }
  if (0 < param_2) {
    puVar4 = &DAT_0047b06c;
    if ((*(int *)(param_1 + 4) == 0xd7b2) ||
       ((param_1 == &DAT_0047d21c && (FUN_0040588a(&DAT_0047d21c), iRam0047d220 == 0xd7b2)))) {
      do {
        iVar1 = *(int *)(param_1 + 0xc);
        iVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
        if (param_2 < iVar3) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
          puVar5 = (undefined1 *)(*(int *)(param_1 + 0x14) + iVar1);
          for (; param_2 != 0; param_2 = param_2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
            puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
          }
          return param_1;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar3;
        param_2 = param_2 - iVar3;
        puVar5 = (undefined1 *)(*(int *)(param_1 + 0x14) + iVar1);
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
          puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
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
  return param_1;
}

