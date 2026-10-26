/*
 * FUN_0045272c at 0045272c
 * undefined __register FUN_0045272c(int * param_1)
 * Address ranges: 0045272c-00452793
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045272c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  byte bVar5;
  int aiStack_40c [256];
  
  bVar5 = 0;
  uVar1 = FUN_00407ce4(param_1 + 0x25,(int *)(param_1[9] + 0x15),0x400);
  if ((char)uVar1 == '\0') {
    piVar3 = param_1 + 0x25;
    piVar4 = aiStack_40c;
    for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + (uint)bVar5 * -2 + 1;
      piVar4 = piVar4 + (uint)bVar5 * -2 + 1;
    }
    FUN_00451cb4(param_1,1,0);
    piVar3 = aiStack_40c;
    piVar4 = param_1 + 0x25;
    for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + (uint)bVar5 * -2 + 1;
      piVar4 = piVar4 + (uint)bVar5 * -2 + 1;
    }
    FUN_0045165c(param_1[9],param_1 + 0x25);
    *(undefined1 *)((int)param_1 + 0x1a) = 1;
  }
  return;
}

