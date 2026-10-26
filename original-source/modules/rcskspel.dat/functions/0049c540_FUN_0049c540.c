/*
 * FUN_0049c540 at 0049c540
 * undefined FUN_0049c540(void)
 * Address ranges: 0049c540-0049c6cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c540(int param_1,int param_2,int *param_3)

{
  if (*param_3 == 1) {
    DAT_006a5b58 = 1;
    if (*(int *)(param_1 + 0x48) == 0) {
      if (*(int *)(param_2 + 0x48) == 0) {
        FUN_004afee0(s__s__d____Two_rails_cannot_collid_004fbae0,
                     s_D__work_rcsk_Code_Engine_Prog_ob_004fbab4,0x101);
      }
      DAT_006a5b5c = 0;
      DAT_006a5b60 = *(undefined4 *)(param_2 + 0x40);
      DAT_006a5b64 = 0;
      _DAT_006a5b68 = param_3[1];
      _DAT_006a5b6c = param_3[2];
      _DAT_006a5b70 = param_3[3];
      FUN_0049ac80(&DAT_006a5b74,param_3[8],param_1,
                   *(int *)(param_1 + 0x44) - *(int *)(param_2 + 0x44));
      return;
    }
    if (*(int *)(param_2 + 0x48) == 0) {
      DAT_006a5b5c = 0;
      DAT_006a5b60 = *(undefined4 *)(param_1 + 0x40);
      DAT_006a5b64 = 0;
      _DAT_006a5b68 = param_3[1];
      _DAT_006a5b6c = param_3[2];
      _DAT_006a5b70 = param_3[3];
      FUN_0049ac80(&DAT_006a5b74,param_3[8],param_1,0);
      DAT_006a5b74 = -DAT_006a5b74;
      DAT_006a5b78 = -DAT_006a5b78;
      DAT_006a5b7c = -DAT_006a5b7c;
      return;
    }
    DAT_006a5b5c = 1;
    DAT_006a5b60 = *(undefined4 *)(param_2 + 0x40);
    DAT_006a5b64 = *(undefined4 *)(param_1 + 0x40);
    _DAT_006a5b68 = param_3[1];
    _DAT_006a5b6c = param_3[2];
    _DAT_006a5b70 = param_3[3];
    FUN_0049ac80(&DAT_006a5b74,param_3[8],param_1,
                 *(int *)(param_1 + 0x44) - *(int *)(param_2 + 0x44));
  }
  return;
}

