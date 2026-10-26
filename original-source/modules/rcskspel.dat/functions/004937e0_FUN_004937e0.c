/*
 * FUN_004937e0 at 004937e0
 * undefined FUN_004937e0(void)
 * Address ranges: 004937e0-0049385c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004937e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1 * 0xd0;
  if ((*(int *)(iVar2 + 0x1c + DAT_0067ee20) == -1) || (*(int *)(iVar2 + 0x20 + DAT_0067ee20) == -1)
     ) {
    FUN_004afee0(s___s___d_Object_not_placed_in_a_c_004fabd4,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0x1ee);
  }
  if (*(int *)(iVar2 + 8 + DAT_0067ee20) == 0) {
    uVar3 = *(undefined4 *)(iVar2 + 0x38 + DAT_0067ee20);
  }
  else {
    uVar3 = 0xffffffff;
  }
  iVar1 = FUN_00494000(param_1,uVar3);
  if (iVar1 != -1) {
    *(int *)(iVar2 + 0x24 + DAT_0067ee20) = iVar1;
    FUN_004944e0(param_1);
  }
  return;
}

