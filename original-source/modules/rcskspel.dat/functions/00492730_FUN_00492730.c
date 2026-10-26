/*
 * FUN_00492730 at 00492730
 * undefined FUN_00492730(void)
 * Address ranges: 00492730-00492800
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00492730(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  param_1 = param_1 * 0xd0;
  iVar1 = *(int *)(param_1 + 0x8c + DAT_0067ee20);
  if (9 < iVar1) {
    FUN_004afee0(s__s__d____Illegal_amount_of_subob_004fa964,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x6ca,iVar1);
  }
  iVar3 = 0;
  if (iVar1 < 1) {
    *(undefined4 *)(param_1 + 0x8c + DAT_0067ee20) = 0;
    return;
  }
  iVar2 = 100;
  do {
    iVar4 = param_1 + DAT_0067ee20;
    if (*(int *)(iVar4 + 0x8c) <= iVar3) {
      FUN_004afee0(s__s__d____Sub_object_not_yet_init_004fa58c,
                   s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x255,iVar3);
    }
    iVar4 = *(int *)(iVar4 + iVar2);
    *(undefined1 *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x90) = 0;
    FUN_0049f570(iVar4);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < iVar1);
  *(undefined4 *)(param_1 + 0x8c + DAT_0067ee20) = 0;
  return;
}

