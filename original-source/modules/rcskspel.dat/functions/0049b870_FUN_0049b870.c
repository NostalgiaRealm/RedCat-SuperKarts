/*
 * FUN_0049b870 at 0049b870
 * undefined FUN_0049b870(void)
 * Address ranges: 0049b870-0049b93e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_0049b870(char *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  char *_Str2;
  int iVar2;
  
  iVar2 = 0;
  _Str2 = (char *)&DAT_00684818;
  while ((*(int *)(_Str2 + 0x80) < 0 || (iVar1 = __strcmpi(param_1,_Str2), iVar1 != 0))) {
    _Str2 = _Str2 + 0x88;
    iVar2 = iVar2 + 1;
    if (0x6a5b57 < (int)_Str2) {
LAB_0049b8ac:
      iVar2 = FUN_0049b580(param_1,param_2,param_5,param_6);
      if (iVar2 == -1) {
        FUN_004afee0(s_Error_during_object_loading____s_004fba64,
                     s_D__work_rcsk_Code_Engine_Prog_ob_004fb9cc,0x1e3);
        return 1;
      }
      *param_3 = (&DAT_00684898)[iVar2 * 0x22];
      *param_4 = (&DAT_0068489c)[iVar2 * 0x22];
      return 1;
    }
  }
  if (iVar2 != -1) {
    *param_3 = (&DAT_00684898)[iVar2 * 0x22];
    *param_4 = (&DAT_0068489c)[iVar2 * 0x22];
    return 1;
  }
  goto LAB_0049b8ac;
}

