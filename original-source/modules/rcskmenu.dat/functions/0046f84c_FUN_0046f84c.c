/*
 * FUN_0046f84c at 0046f84c
 * undefined __register FUN_0046f84c(int param_1, undefined4 param_2)
 * Address ranges: 0046f84c-0046fa1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046f84c(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  char cVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 unaff_EBX;
  undefined3 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  puStack_20 = &LAB_0046fa1f;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  uVar3 = (undefined3)((uint)unaff_EBX >> 8);
  puVar1 = &stack0xfffffffc;
  if (*(char *)(param_1 + 0x338) != '\0') {
    cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                         CONCAT31(uVar3,*(char *)(param_1 + 0x338)) - 1);
    if (cVar2 == '\0') {
      FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e234 + (uint)*(byte *)(param_1 + 0x338) * 0x10)
                  );
      param_2 = extraout_EDX_00;
      puVar1 = puStack_1c;
    }
    else {
      FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e23c + (uint)*(byte *)(param_1 + 0x338) * 0x10)
                  );
      param_2 = extraout_EDX;
      puVar1 = puStack_1c;
    }
  }
  puStack_1c = puVar1;
  cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                       CONCAT31((int3)((uint)param_2 >> 8),*(undefined1 *)(param_1 + 0x338)));
  if (cVar2 == '\0') {
    FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047e240 + (uint)*(byte *)(param_1 + 0x338) * 0x10));
  }
  else {
    FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047e248 + (uint)*(byte *)(param_1 + 0x338) * 0x10));
  }
  if (*(byte *)(param_1 + 0x338) < 5) {
    cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                         CONCAT31(uVar3,*(byte *)(param_1 + 0x338)) + 1);
    if (cVar2 == '\0') {
      FUN_00403be8((int *)&local_10,
                   *(int *)(&DAT_0047e254 + (uint)*(byte *)(param_1 + 0x338) * 0x10));
    }
    else {
      FUN_00403be8((int *)&local_10,
                   *(int *)(&DAT_0047e25c + (uint)*(byte *)(param_1 + 0x338) * 0x10));
    }
  }
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x314) + 300),local_8);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x30c) + 300),local_10);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x310) + 300),local_c);
  (**(code **)(**(int **)(param_1 + 0x31c) + 0x5c))
            (*(int **)(param_1 + 0x31c),
             CONCAT31((int3)((uint)extraout_EDX_01 >> 8),*(char *)(param_1 + 0x338) == '\x05') ^ 1);
  (**(code **)(**(int **)(param_1 + 0x2f4) + 0x5c))
            (*(int **)(param_1 + 0x2f4),
             CONCAT31((int3)((uint)extraout_EDX_02 >> 8),*(char *)(param_1 + 0x338) == '\0') ^ 1);
  FUN_0043f67c(*(int *)(param_1 + 0x324),
               *(uint **)(PTR_PTR_0047c908 + (uint)*(byte *)(param_1 + 0x338) * 4));
  FUN_0043fb28(*(int **)(param_1 + 0x31c));
  FUN_0043fb28(*(int **)(param_1 + 0x2f4));
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0046fa26;
  puStack_20 = (undefined1 *)0x46fa1e;
  FUN_00403b74((int *)&local_10,3);
  return;
}

