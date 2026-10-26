/*
 * FUN_004022dc at 004022dc
 * undefined4 __register FUN_004022dc(int param_1)
 * Address ranges: 004022dc-0040246d;00402475-0040247d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004022dc(int param_1)

{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  
  DAT_0047d434 = 0;
  if ((DAT_0047d430 == '\0') && (cVar2 = FUN_00401a80(), cVar2 == '\0')) {
    DAT_0047d434 = 8;
    return 8;
  }
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (DAT_0047d049 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  puVar6 = (uint *)(param_1 + -4);
  uVar5 = *puVar6;
  if ((uVar5 & 2) == 0) {
    DAT_0047d434 = 9;
    goto LAB_00402445;
  }
  _DAT_0047d424 = _DAT_0047d424 + -1;
  _DAT_0047d428 = _DAT_0047d428 - ((uVar5 & 0x7ffffffc) - 4);
  if ((uVar5 & 1) != 0) {
    uVar1 = *(uint *)(param_1 + -8);
    if (((int)uVar1 < 0xc) || ((uVar1 & 0x80000003) != 0)) {
      DAT_0047d434 = 10;
      goto LAB_00402445;
    }
    puVar6 = (uint *)((int)puVar6 - uVar1);
    if (uVar1 != puVar6[2]) {
      DAT_0047d434 = 10;
      goto LAB_00402445;
    }
    uVar5 = uVar5 + uVar1;
    FUN_00401c24((int *)puVar6);
  }
  uVar5 = uVar5 & 0x7ffffffc;
  puVar3 = (uint *)((int)puVar6 + uVar5);
  if (puVar3 == DAT_0047d48c) {
    DAT_0047d48c = (uint *)((int)DAT_0047d48c - uVar5);
    DAT_0047d488 = DAT_0047d488 + uVar5;
    if (0x3c00 < DAT_0047d488) {
      FUN_00401efc();
    }
    FUN_004036a4();
    return 0;
  }
  if ((*puVar3 & 2) == 0) {
    if (((puVar3[1] == 0) || (*puVar3 == 0)) || ((int)puVar3[2] < 0xc)) {
      DAT_0047d434 = 0xb;
      goto LAB_00402445;
    }
    uVar5 = uVar5 + puVar3[2];
    FUN_00401c24((int *)puVar3);
  }
  else {
    if ((*puVar3 & 0x7ffffffc) < 4) {
      DAT_0047d434 = 0xb;
      goto LAB_00402445;
    }
    *puVar3 = *puVar3 | 1;
  }
  FUN_00401e74(puVar6,uVar5);
LAB_00402445:
  uVar4 = 0;
  *in_FS_OFFSET = uStack_20;
  if (DAT_0047d049 != '\0') {
    uStack_20 = 0x40246d;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  return uVar4;
}

