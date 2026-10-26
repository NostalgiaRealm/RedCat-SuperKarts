/*
 * FUN_00430804 at 00430804
 * undefined __register FUN_00430804(int * param_1, char param_2, undefined4 param_3, int param_4)
 * Address ranges: 00430804-0043093c;00430955-004309b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430804(int *param_1,char param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  
  iVar3 = *(int *)(*(int *)(param_4 + -4) + 8) - **(int **)(param_4 + -4);
  if ((iVar3 < 0) || ((byte)(param_2 - 3U) < 2)) {
    iVar3 = param_1[0xe];
  }
  local_14 = *(int *)(*(int *)(param_4 + -4) + 0xc) - *(int *)(*(int *)(param_4 + -4) + 4);
  if ((local_14 < 0) || ((byte)(param_2 - 1U) < 2)) {
    local_14 = param_1[0xf];
  }
  if ((param_2 == '\x01') && (*(char *)((int)param_1 + 0x213) == '\x02')) {
    local_c = param_1[0xc];
    local_10 = param_1[0xd];
    iVar3 = (**(code **)PTR_DAT_0047c734)();
  }
  else {
    local_c = **(int **)(param_4 + -4);
    local_10 = *(int *)(*(int *)(param_4 + -4) + 4);
  }
  if (param_2 == '\x01') {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 4);
    *piVar1 = *piVar1 + local_14;
  }
  else if (param_2 == '\x02') {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 0xc);
    *piVar1 = *piVar1 - local_14;
    local_10 = *(int *)(*(int *)(param_4 + -4) + 0xc);
  }
  else if (param_2 == '\x03') {
    **(int **)(param_4 + -4) = **(int **)(param_4 + -4) + iVar3;
  }
  else if (param_2 == '\x04') {
    piVar1 = (int *)(*(int *)(param_4 + -4) + 8);
    *piVar1 = *piVar1 - iVar3;
    local_c = *(int *)(*(int *)(param_4 + -4) + 8);
  }
  (**(code **)(*param_1 + 0x7c))(param_1,local_c,local_10,local_14,iVar3);
  if (*(char *)((int)param_1 + 0x213) == '\x02') {
    iVar3 = iVar3 - local_c;
    local_14 = local_14 - local_10;
  }
  iVar2 = param_1[0xe];
  if ((iVar3 != iVar2) || (param_1[0xf] != local_14)) {
    switch(param_2) {
    case '\x01':
      piVar1 = (int *)(*(int *)(param_4 + -4) + 4);
      *piVar1 = *piVar1 - (local_14 - param_1[0xf]);
      break;
    case '\x02':
      piVar1 = (int *)(*(int *)(param_4 + -4) + 0xc);
      *piVar1 = *piVar1 + (local_14 - param_1[0xf]);
      break;
    case '\x03':
      **(int **)(param_4 + -4) = **(int **)(param_4 + -4) - (iVar3 - iVar2);
      break;
    case '\x04':
      piVar1 = (int *)(*(int *)(param_4 + -4) + 8);
      *piVar1 = *piVar1 + (iVar3 - iVar2);
      break;
    case '\x05':
      piVar1 = (int *)(*(int *)(param_4 + -4) + 8);
      *piVar1 = *piVar1 + (iVar3 - iVar2);
      piVar1 = (int *)(*(int *)(param_4 + -4) + 0xc);
      *piVar1 = *piVar1 + (local_14 - param_1[0xf]);
    }
  }
  return;
}

