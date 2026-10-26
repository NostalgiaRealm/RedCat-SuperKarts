/*
 * FUN_0047e030 at 0047e030
 * undefined FUN_0047e030(void)
 * Address ranges: 0047e030-0047e0f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047e030(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char *_Str1;
  int iVar2;
  undefined1 *puVar3;
  char *_Str2;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  if (DAT_00544fd8 != 0) {
    piVar4 = &DAT_00544fd4;
    do {
      _Str2 = "";
      if ((char *)*piVar4 != (char *)0x0) {
        _Str2 = (char *)*piVar4;
      }
      _Str1 = *(char **)(param_1 + 4);
      if (_Str1 == (char *)0x0) {
        _Str1 = "";
      }
      iVar2 = __strcmpi(_Str1,_Str2);
      if (iVar2 == 0) {
        puVar3 = *(undefined1 **)(param_1 + 4);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004afce0(s__s__d____Creating_item__s_004f8868,
                     s_D__work_rcsk_Code_game_Requester_004f8838,0xa1,puVar3);
        (*(code *)(&DAT_00544fe0)[iVar5 * 5])(param_2,param_3,param_4);
        return;
      }
      piVar1 = piVar4 + 6;
      piVar4 = piVar4 + 5;
      iVar5 = iVar5 + 1;
    } while (*piVar1 != 0);
  }
  FUN_004afce0(s__s__d____Creating_default_item_004f8818,s_D__work_rcsk_Code_game_Requester_004f87e8
               ,0x95);
  (*(code *)(&DAT_00544fe0)[iVar5 * 5])(param_2,param_3,param_4);
  return;
}

