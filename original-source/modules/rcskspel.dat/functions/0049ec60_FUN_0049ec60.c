/*
 * FUN_0049ec60 at 0049ec60
 * undefined FUN_0049ec60(void)
 * Address ranges: 0049ec60-0049ed00
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0049ec60(int *param_1,char *param_2)

{
  char *_Str2;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  FUN_0049f2a0(*param_1 != 0,s__s___d__Sound_types_not_allocate_004fc4dc,
               s_D__work_rcracer_oursoundlib_soun_004fc4a8,0xc5);
  iVar4 = 0;
  if (0 < param_1[1]) {
    iVar2 = 0;
    do {
      _Str2 = *(char **)(iVar2 + 0x2c + *param_1);
      if (_Str2 == (char *)0x0) {
        _Str2 = "";
      }
      iVar1 = __strcmpi(param_2,_Str2);
      if (iVar1 == 0) {
        iVar3 = *param_1 + iVar4 * 0x38;
        break;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar4 < param_1[1]);
  }
  FUN_0049f2a0(iVar3 != 0,s__s___d__Sound_type__s_not_found__004fc504,
               s_D__work_rcracer_oursoundlib_soun_004fc4a8,0xd2,param_2);
  return iVar3;
}

