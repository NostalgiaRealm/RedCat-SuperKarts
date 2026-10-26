/*
 * FUN_00439820 at 00439820
 * undefined __register FUN_00439820(HMENU param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00439820-004398bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439820(HMENU param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  UINT UVar3;
  UINT uId;
  
  iVar1 = GetMenuItemCount(param_1);
  pcVar2 = (char *)(param_4 + -0x200);
  uId = 0;
  while (((int)uId < iVar1 && (pcVar2 < (char *)(param_4 - 5U)))) {
    FUN_00439dbc(*(int *)(param_4 + -0x204),param_1,uId,0x400,(int)(param_4 - 5U) - (int)pcVar2,
                 pcVar2);
    pcVar2 = FUN_00408358(pcVar2);
    UVar3 = GetMenuState(param_1,uId,0x400);
    if ((UVar3 & 2) != 0) {
      *pcVar2 = '$';
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
    }
    if ((UVar3 & 0x40) != 0) {
      *pcVar2 = '@';
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
    }
    if ((UVar3 & 1) != 0) {
      *pcVar2 = '#';
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
    }
    *pcVar2 = ';';
    pcVar2 = pcVar2 + 1;
    *pcVar2 = '\0';
    uId = uId + 1;
  }
  return;
}

