/*
 * FUN_0044bc4c at 0044bc4c
 * undefined __register FUN_0044bc4c(int * param_1, int param_2)
 * Address ranges: 0044bc4c-0044bd51;0044bd71-0044bd82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bc4c(int *param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_1c [4];
  int local_c;
  int *local_8;
  
  puStack_2c = &stack0xfffffffc;
  local_c = param_2;
  local_8 = param_1;
  if ((char)param_1[0x13] == '\0') {
    puStack_2c = (undefined1 *)0x44bd7c;
    FUN_0044420c(param_1,param_2);
  }
  else {
    *(undefined1 *)(param_1 + 0x7e) = 1;
    puStack_30 = &LAB_0044bd6a;
    uStack_34 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_34;
    piVar4 = (int *)(*(int *)(param_2 + 4) + 0x44);
    piVar5 = local_1c;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    cVar1 = *(char *)((int)local_8 + 0x4b);
    if (cVar1 == '\x01') {
      puVar2 = &stack0xfffffffc;
      if (local_8[0xf] == 0) {
        FUN_0043eed0(local_8,local_1c[3] - local_1c[1]);
        puVar2 = puStack_2c;
      }
    }
    else if (cVar1 == '\x02') {
      puVar2 = &stack0xfffffffc;
      if (local_8[0xf] == 0) {
        puStack_2c = &stack0xfffffffc;
        (**(code **)(*local_8 + 0x7c))
                  (local_8,local_8[0xc],local_8[0xd] - (local_1c[3] - local_1c[1]),
                   local_1c[3] - local_1c[1],local_8[0xe]);
        puVar2 = puStack_2c;
      }
    }
    else if (cVar1 == '\x03') {
      puVar2 = &stack0xfffffffc;
      if (local_8[0xe] == 0) {
        puStack_2c = &stack0xfffffffc;
        FUN_0043eeb0(local_8,local_1c[2] - local_1c[0]);
        puVar2 = puStack_2c;
      }
    }
    else {
      puVar2 = &stack0xfffffffc;
      if ((cVar1 == '\x04') && (puVar2 = &stack0xfffffffc, local_8[0xe] == 0)) {
        puStack_2c = &stack0xfffffffc;
        (**(code **)(*local_8 + 0x7c))
                  (local_8,local_8[0xc] - (local_1c[2] - local_1c[0]),local_8[0xd],local_8[0xf],
                   local_1c[2] - local_1c[0]);
        puVar2 = puStack_2c;
      }
    }
    puStack_2c = puVar2;
    FUN_0044420c(local_8,local_c);
    FUN_004036a4();
  }
  return;
}

