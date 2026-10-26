/*
 * FUN_00405fd4 at 00405fd4
 * undefined __register FUN_00405fd4(void)
 * Address ranges: 00405fd4-004060bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405fd4(void)

{
  WORD WVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined4 *in_FS_OFFSET;
  bool bVar3;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  
  puStack_8 = &stack0xfffffffc;
  puStack_c = &LAB_004060bc;
  uStack_10 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_10;
  bVar3 = _DAT_0047d42c == 0;
  _DAT_0047d42c = _DAT_0047d42c + -1;
  if (bVar3) {
    DAT_0047d038 = 0;
    DAT_0047d040 = 0;
    DAT_0047d044 = 0;
    DAT_0047d04a = 2;
    DAT_0047d04b = 2;
    DAT_0047d04c = 3;
    _DAT_0047d3f4 = 0;
    _DAT_0047d404 = 1;
    _DAT_0047d414 = 10;
    _DAT_0047d41c = 0x80020004;
    DAT_0047d3e8 = 0x404864;
    DAT_0047d3ec = thunk_FUN_004027a0;
    _DAT_0047d3f0 = 0x404864;
    uVar2 = FUN_00402cf4();
    if ((char)uVar2 != '\0') {
      FUN_00402d24();
    }
    FUN_00402de8();
    FUN_0040576a((undefined4 *)&DAT_0047d050,"");
    FUN_0040576a((undefined4 *)&DAT_0047d21c,"");
    _DAT_0047d030 = GetCommandLineA();
    WVar1 = FUN_00401390();
    DAT_0047d02c = CONCAT22(extraout_var,WVar1);
    _DAT_0047d024 = GetCurrentThreadId();
  }
  *in_FS_OFFSET = uStack_10;
  return;
}

