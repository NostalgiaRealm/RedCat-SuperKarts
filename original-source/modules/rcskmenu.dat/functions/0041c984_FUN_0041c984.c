/*
 * FUN_0041c984 at 0041c984
 * undefined __register FUN_0041c984(int param_1, HBITMAP param_2, HPALETTE param_3, undefined4 * param_4)
 * Address ranges: 0041c984-0041ca12;0041ca39-0041ca41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041c984(int param_1,HBITMAP param_2,HPALETTE param_3,undefined4 *param_4)

{
  HPALETTE pHVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_78;
  undefined1 *puStack_74;
  undefined1 *puStack_70;
  undefined4 local_60 [21];
  HPALETTE local_c;
  HPALETTE local_8;
  
  puVar3 = local_60;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_4;
    param_4 = param_4 + 1;
    puVar3 = puVar3 + 1;
  }
  puStack_70 = (undefined1 *)0x41c9a9;
  FUN_0041cf04(param_1);
  local_8 = (HPALETTE)0x0;
  local_c = (HPALETTE)0x0;
  puStack_74 = &LAB_0041ca13;
  uStack_78 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_78;
  puStack_70 = &stack0xfffffffc;
  pHVar1 = param_3;
  if (param_3 != DAT_0047d67c) {
    puStack_70 = &stack0xfffffffc;
    pHVar1 = FUN_0041c580(param_3);
  }
  local_c = pHVar1;
  local_8 = FUN_0041bf24(param_2,param_3,local_c,*(int *)(param_1 + 0x24),(int)local_60);
  uVar4 = 0;
  FUN_0041d1c4(param_1,local_8,local_c,(int *)0x0,*(undefined1 *)(*(int *)(param_1 + 0x20) + 0x70),
               local_60);
  *in_FS_OFFSET = uVar4;
  return;
}

