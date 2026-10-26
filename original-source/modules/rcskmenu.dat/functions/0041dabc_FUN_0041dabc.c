/*
 * FUN_0041dabc at 0041dabc
 * undefined __register FUN_0041dabc(int * param_1, byte param_2)
 * Address ranges: 0041dabc-0041db38
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041dabc(int *param_1,byte param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 local_60 [4];
  ushort local_50;
  ushort local_4e;
  undefined4 local_48;
  ushort local_3c;
  ushort local_3a;
  
  bVar6 = 0;
  iVar1 = param_1[8];
  if ((*(short *)(iVar1 + 0x3c) == 1) && (*(short *)(iVar1 + 0x3e) == 1)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  if (param_2 != bVar2) {
    FUN_0041cf14((int)param_1);
    puVar4 = (undefined4 *)(iVar1 + 0x18);
    puVar5 = local_60;
    for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
      puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
    }
    local_48 = 0;
    local_50 = (ushort)param_2;
    local_4e = local_50;
    local_3c = local_50;
    local_3a = local_50;
    FUN_0041c984((int)param_1,*(HBITMAP *)(iVar1 + 8),*(HPALETTE *)(iVar1 + 0x10),local_60);
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

