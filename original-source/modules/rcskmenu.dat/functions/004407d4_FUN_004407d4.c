/*
 * FUN_004407d4 at 004407d4
 * undefined __register FUN_004407d4(int param_1, int * param_2)
 * Address ranges: 004407d4-00440854
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004407d4(int param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_2;
  if (iVar2 == 0xc) {
    uVar3 = FUN_00408548((char *)param_2[2]);
    FUN_00408574(*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = uVar3;
    FUN_0043f24c(param_1,*param_2,param_2[1],param_2[2]);
  }
  else if (iVar2 == 0xd) {
    pcVar1 = *(char **)(param_1 + 0x54);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "";
    }
    pcVar1 = FUN_004083d0((char *)param_2[2],pcVar1,param_2[1] + -1);
    iVar2 = FUN_00408340(pcVar1);
    param_2[3] = iVar2;
  }
  else if (iVar2 == 0xe) {
    if (*(char **)(param_1 + 0x54) == (char *)0x0) {
      param_2[3] = 0;
    }
    else {
      iVar2 = FUN_00408340(*(char **)(param_1 + 0x54));
      param_2[3] = iVar2;
    }
  }
  return;
}

