/*
 * FUN_0043d710 at 0043d710
 * undefined FUN_0043d710(void)
 * Address ranges: 0043d710-0043d809
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_0043d710(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  void *pvVar3;
  undefined1 local_11;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd5ad;
  local_c = ExceptionList;
  if (DAT_0053c208 == (undefined1 *)0x0) {
    ExceptionList = &local_c;
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined1 *)0x0) {
      DAT_0053c208 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = local_11;
      puVar2[1] = local_11;
      puVar2[8] = 0;
      local_4 = 1;
      if (DAT_0053c210 == (undefined4 *)0x0) {
        DAT_0053c210 = operator_new(0x18);
        DAT_0053c210[1] = 0;
        DAT_0053c210[5] = 1;
        *DAT_0053c210 = 0;
        DAT_0053c210[2] = 0;
      }
      puVar1 = DAT_0053c210;
      DAT_0053c20c = DAT_0053c20c + 1;
      pvVar3 = operator_new(0x18);
      *(undefined4 **)((int)pvVar3 + 4) = puVar1;
      *(undefined4 *)((int)pvVar3 + 0x14) = 0;
      *(void **)(puVar2 + 4) = pvVar3;
      *(undefined4 *)(puVar2 + 0xc) = 0;
      *(void **)pvVar3 = pvVar3;
      *(int *)(*(int *)(puVar2 + 4) + 8) = *(int *)(puVar2 + 4);
      DAT_0053c208 = puVar2;
    }
    local_4 = 0xffffffff;
    if (DAT_0053c208 == (undefined1 *)0x0) {
      FUN_004afee0(s_Unable_to_create_map___s__d__004ec3ec,
                   s_D__work_rcsk_Code_game_Tob_hazar_004ec3c4,0xdc);
    }
  }
  ExceptionList = local_c;
  return DAT_0053c208;
}

