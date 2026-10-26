/*
 * FUN_00402650 at 00402650
 * undefined4 __register FUN_00402650(undefined4 * param_1, uint param_2)
 * Address ranges: 00402650-00402700;00402708-00402710
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402650(undefined4 *param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  
  if ((DAT_0047d430 == '\0') && (cVar1 = FUN_00401a80(), cVar1 == '\0')) {
    return 0;
  }
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (DAT_0047d049 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  uVar2 = FUN_00402480((int)param_1,param_2);
  if ((char)uVar2 == '\0') {
    puVar3 = FUN_00402154(param_2);
    uVar4 = (param_1[-1] & 0x7ffffffc) - 4;
    if ((int)param_2 < (int)uVar4) {
      uVar4 = param_2;
    }
    if (puVar3 != (uint *)0x0) {
      FUN_0040282c(param_1,puVar3,uVar4);
      FUN_004022dc((int)param_1);
    }
  }
  uVar2 = 0;
  *in_FS_OFFSET = uStack_20;
  if (DAT_0047d049 != '\0') {
    uStack_20 = 0x402700;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d438);
  }
  return uVar2;
}

