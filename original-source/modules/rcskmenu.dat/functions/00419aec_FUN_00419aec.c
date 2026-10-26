/*
 * FUN_00419aec at 00419aec
 * undefined __register FUN_00419aec(HANDLE param_1, uint * param_2, uint param_3)
 * Address ranges: 00419aec-00419bcf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419aec(HANDLE param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined1 auStack_60 [4];
  uint local_5c;
  uint local_58;
  short local_50;
  short local_4e;
  uint local_48 [15];
  
  local_48[0] = 0;
  iVar1 = GetObjectA(param_1,0x54,auStack_60);
  if (iVar1 == 0) {
    FUN_00418c6c();
  }
  else if ((iVar1 < 0x40) || (local_48[0] < 0x28)) {
    FUN_00402b54(param_2,0x28,0);
    *param_2 = 0x28;
    param_2[1] = local_5c;
    param_2[2] = local_58;
  }
  else {
    puVar3 = local_48;
    puVar4 = param_2;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (param_3 == 2) {
    *(undefined2 *)((int)param_2 + 0xe) = 1;
  }
  else if (param_3 - 3 < 0xe) {
    *(undefined2 *)((int)param_2 + 0xe) = 4;
    param_2[8] = param_3;
  }
  else if (param_3 - 0x11 < 0xf0) {
    *(undefined2 *)((int)param_2 + 0xe) = 8;
    param_2[8] = param_3;
  }
  else {
    *(short *)((int)param_2 + 0xe) = local_4e * local_50;
  }
  *(undefined2 *)(param_2 + 3) = 1;
  if (param_2[8] < param_2[9]) {
    param_2[9] = param_2[8];
  }
  if (param_2[5] == 0) {
    iVar1 = FUN_00418f1c(param_2[1],(uint)*(ushort *)((int)param_2 + 0xe),0x20);
    uVar2 = (int)param_2[2] >> 0x1f;
    param_2[5] = iVar1 * ((param_2[2] ^ uVar2) - uVar2);
  }
  return;
}

