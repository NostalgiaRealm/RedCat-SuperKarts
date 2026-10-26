/*
 * FUN_0043d110 at 0043d110
 * undefined __register FUN_0043d110(int param_1, undefined4 * param_2)
 * Address ranges: 0043d110-0043d18c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d110(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_1c [4];
  
  piVar4 = local_1c;
  for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = *param_2;
    param_2 = param_2 + 1;
    piVar4 = piVar4 + 1;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iVar3 < local_1c[0]) || (local_1c[2] < iVar3)) {
    uVar1 = FUN_0043d0ec(local_1c[0] - iVar3,local_1c[2] - iVar3);
  }
  else {
    uVar1 = 0;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  if ((iVar3 < local_1c[1]) || (local_1c[3] < iVar3)) {
    uVar2 = FUN_0043d0ec(local_1c[1] - iVar3,local_1c[3] - iVar3);
  }
  else {
    uVar2 = 0;
  }
  if ((uVar1 != 0) || (uVar2 != 0)) {
    OffsetRect((LPRECT)(param_1 + 0x44),-uVar1,-uVar2);
  }
  return;
}

