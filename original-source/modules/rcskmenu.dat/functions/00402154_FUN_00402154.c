/*
 * FUN_00402154 at 00402154
 * uint * __register FUN_00402154(int param_1)
 * Address ranges: 00402154-004022c7;004022cf-004022d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_00402154(int param_1)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  
  if ((DAT_0047d430 == '\0') && (cVar2 = FUN_00401a80(), cVar2 == '\0')) {
    return (uint *)0x0;
  }
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  if (DAT_0047d049 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  puVar4 = DAT_0047d48c;
  uVar5 = param_1 + 7U & 0xfffffffc;
  if ((int)uVar5 < 0xc) {
    uVar5 = 0xc;
  }
  if ((int)uVar5 < 0x1001) {
    uVar3 = uVar5;
    if ((int)uVar5 < 0) {
      uVar3 = uVar5 + 3;
    }
    puVar1 = *(uint **)(DAT_0047d490 + -0xc + ((int)uVar3 >> 2) * 4);
    if (puVar1 != (uint *)0x0) {
      *(uint *)((int)puVar1 + uVar5) = *(uint *)((int)puVar1 + uVar5) & 0xfffffffe;
      puVar4 = (uint *)puVar1[1];
      if (puVar1 == puVar4) {
        uVar3 = uVar5;
        if ((int)uVar5 < 0) {
          uVar3 = uVar5 + 3;
        }
        *(undefined4 *)(DAT_0047d490 + -0xc + ((int)uVar3 >> 2) * 4) = 0;
      }
      else {
        uVar3 = uVar5;
        if ((int)uVar5 < 0) {
          uVar3 = uVar5 + 3;
        }
        *(uint **)(DAT_0047d490 + -0xc + ((int)uVar3 >> 2) * 4) = puVar4;
        uVar3 = *puVar1;
        *(uint **)(uVar3 + 4) = puVar4;
        *puVar4 = uVar3;
      }
      *puVar1 = puVar1[2] | 2;
      _DAT_0047d424 = _DAT_0047d424 + 1;
      _DAT_0047d428 = _DAT_0047d428 + (uVar5 - 4);
      FUN_004036a4();
      return puVar1 + 1;
    }
  }
  if ((int)uVar5 <= DAT_0047d488) {
    DAT_0047d488 = DAT_0047d488 - uVar5;
    if (DAT_0047d488 < 0xc) {
      uVar5 = uVar5 + DAT_0047d488;
      DAT_0047d488 = 0;
    }
    DAT_0047d48c = (uint *)((int)DAT_0047d48c + uVar5);
    *puVar4 = uVar5 | 2;
    _DAT_0047d424 = _DAT_0047d424 + 1;
    _DAT_0047d428 = _DAT_0047d428 + (uVar5 - 4);
    FUN_004036a4();
    return puVar4 + 1;
  }
  FUN_00402060(uVar5);
  puVar4 = (uint *)0x0;
  *in_FS_OFFSET = uStack_24;
  if (DAT_0047d049 != '\0') {
    uStack_24 = 0x4022c7;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  return puVar4;
}

