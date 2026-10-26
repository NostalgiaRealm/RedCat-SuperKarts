/*
 * FUN_00404130 at 00404130
 * undefined FUN_00404130(void)
 * Address ranges: 00404130-00404250
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404130(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 8;
  iVar4 = param_1 * 0xd0;
  iVar1 = *(int *)(iVar4 + 0x38 + DAT_0067ee20);
  if ((iVar1 != 1) && (iVar1 != 0)) {
    FUN_004afee0(s__s__d___obj_side__d_____d_is_ill_004ddb68,
                 s_D__work_rcsk_Code_game_ai_main_C_004ddb44,0x36d,param_1,iVar1);
  }
  if (*(int *)(iVar4 + 0x38 + DAT_0067ee20) == 1) {
    local_8 = 0x12;
  }
  if (*(int *)(iVar4 + 0x38 + DAT_0067ee20) == 0) {
    local_8 = 0x28;
  }
  iVar1 = *(int *)(iVar4 + 0x10 + DAT_0067ee20);
  iVar3 = iVar1 * 0x6c;
  iVar2 = *(int *)(iVar3 + 0x24 + DAT_00504f98);
  *(undefined4 *)(iVar3 + 0x14 + DAT_00504f98) = param_2;
  if (*(int *)(iVar3 + 0x24 + DAT_00504f98) == 0) {
    *(undefined4 *)(iVar3 + 0x18 + DAT_00504f98) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x18 + DAT_00504f98) =
         *(undefined4 *)(DAT_00504fe0 + 0x14 + iVar2 * 0x2c);
  }
  *(undefined4 *)(iVar4 + 0x48 + DAT_0067ee20) = 1;
  if ((1 < iVar2) && (iVar2 < 6)) {
    FUN_004afce0(s_my_fault_004ddb90);
    FUN_004057f0(param_1,&local_4,&local_8);
    FUN_00405380(iVar1,*(undefined4 *)(iVar4 + 0x38 + DAT_0067ee20),local_4);
    FUN_00405380(iVar1,*(undefined4 *)(iVar4 + 0x38 + DAT_0067ee20),local_8);
  }
  return;
}

