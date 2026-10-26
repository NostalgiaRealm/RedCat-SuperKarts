/*
 * FUN_0042aa04 at 0042aa04
 * undefined __register FUN_0042aa04(int param_1, int param_2, int param_3)
 * Address ranges: 0042aa04-0042aaa7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042aa04(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != param_2) {
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x1e) = 1;
      *(undefined1 *)(*(int *)(param_1 + 500) + 0x1e) = 1;
    }
    FUN_0042a14c(*(int *)(param_1 + 0x1f0),0);
    FUN_0042a14c(*(int *)(param_1 + 500),0);
    if (*(char *)(param_1 + 0x1f8) == '\0') {
      iVar1 = *(int *)(param_1 + 0x1f0);
      if (*(char *)(iVar1 + 0x1e) != '\0') {
        iVar2 = MulDiv(*(int *)(iVar1 + 0x10),param_2,param_3);
        FUN_0042a29c(iVar1,iVar2);
      }
      iVar1 = *(int *)(param_1 + 500);
      if (*(char *)(iVar1 + 0x1e) != '\0') {
        iVar2 = MulDiv(*(int *)(iVar1 + 0x10),param_2,param_3);
        FUN_0042a29c(iVar1,iVar2);
      }
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 0x1f0) + 0x1e) = 0;
  *(undefined1 *)(*(int *)(param_1 + 500) + 0x1e) = 0;
  return;
}

