/*
 * FUN_0044f440 at 0044f440
 * undefined FUN_0044f440(void)
 * Address ranges: 0044f440-0044f4f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044f440(int *param_1,int param_2)

{
  int iVar1;
  char *_Str1;
  undefined1 *puVar2;
  uint uVar3;
  char *_Str2;
  
  uVar3 = 0;
  while( true ) {
    if ((param_1[10] == 0) || ((uint)((param_1[0xb] - param_1[10]) / 0x60) <= uVar3)) {
      puVar2 = *(undefined1 **)(param_2 + 4);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_004d2404;
      }
      FUN_004afee0(s___s___Animation___s__not_found_a_004f0f04,
                   s_D__work_rcsk_Code_game_msh_mshAn_004f0ed8,puVar2,0xc9);
      return;
    }
    _Str2 = "";
    if (*(char **)(param_2 + 4) != (char *)0x0) {
      _Str2 = *(char **)(param_2 + 4);
    }
    iVar1 = FUN_0044ebc0();
    _Str1 = *(char **)(iVar1 + 4);
    if (_Str1 == (char *)0x0) {
      _Str1 = "";
    }
    iVar1 = __strcmpi(_Str1,_Str2);
    if (iVar1 == 0) break;
    uVar3 = uVar3 + 1;
  }
  FUN_004afce0(s_Adding_004f0ed0);
  (**(code **)(*param_1 + 4))(uVar3);
  return;
}

