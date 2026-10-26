/*
 * FUN_00455190 at 00455190
 * undefined FUN_00455190(void)
 * Address ranges: 00455190-004553d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455190(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543d60;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543d80;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543da0;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543dc0;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,1,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543de0;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,1,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543e00;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
  puVar3 = &DAT_00543e20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,3);
  puVar3 = &DAT_00543e40;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,5);
  puVar3 = &DAT_00543e60;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00543e80;
  for (iVar2 = 0x78; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  iVar2 = 0xf;
  do {
    FUN_004553e0(0x41700000,0x41700000,0,0,0x42c80000,0x3f800000,0x3f800000,1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

