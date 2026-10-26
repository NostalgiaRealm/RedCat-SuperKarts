/*
 * FUN_0041df60 at 0041df60
 * undefined __register FUN_0041df60(int param_1, undefined2 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 0041df60-0041dfd9;0041dff4-0041dffc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041df60(int param_1,undefined2 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  HPALETTE pHVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *in_FS_OFFSET;
  byte bVar6;
  undefined4 uStackY_7c;
  undefined1 *puStackY_78;
  undefined1 *puStackY_74;
  undefined4 local_5c [5];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 *local_8;
  
  bVar6 = 0;
  *param_2 = 2;
  local_8 = param_3;
  FUN_0041cf14(param_1);
  iVar1 = *(int *)(param_1 + 0x20);
  puVar4 = (undefined4 *)(iVar1 + 0x18);
  puVar5 = local_5c;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
    puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
  }
  local_44 = 0;
  local_48 = 0;
  puStackY_74 = (undefined1 *)0x41dfad;
  pHVar2 = FUN_0041bf24(*(HBITMAP *)(iVar1 + 8),*(HPALETTE *)(iVar1 + 0x10),
                        *(HPALETTE *)(iVar1 + 0x10),*(int *)(param_1 + 0x24),(int)local_5c);
  *local_8 = pHVar2;
  puStackY_78 = &LAB_0041dfda;
  uStackY_7c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_7c;
  puStackY_74 = &stack0xfffffffc;
  pHVar2 = FUN_0041c580(*(HPALETTE *)(*(int *)(param_1 + 0x20) + 0x10));
  *param_4 = pHVar2;
  *in_FS_OFFSET = uStackY_7c;
  return;
}

