/*
 * FUN_0049c890 at 0049c890
 * undefined FUN_0049c890(void)
 * Address ranges: 0049c890-0049c8e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049c890(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 4);
  iVar2 = 2;
  iVar1 = DAT_006a5e80;
  do {
    if (((*(int *)(iVar1 + 8 + piVar3[-1] * 0x48) == *(int *)(param_2 * 0x48 + 8 + iVar1)) &&
        (*(int *)(param_2 * 0x48 + 0x2c + iVar1) == 4)) && (*piVar3 != param_2)) {
      FUN_004a46e0(param_2);
      *piVar3 = param_2;
      iVar1 = DAT_006a5e80;
    }
    piVar3 = (int *)((int)piVar3 + 9);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

