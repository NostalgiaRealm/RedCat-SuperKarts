/*
 * FUN_00419274 at 00419274
 * undefined __register FUN_00419274(int param_1, int param_2)
 * Address ranges: 00419274-004192c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419274(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  _SYSTEM_INFO local_30;
  int local_c;
  int local_8;
  
  local_c = param_2;
  local_8 = param_1;
  GetSystemInfo(&local_30);
  local_c = local_c + -1;
  if (-1 < local_c) {
    if (local_30.wProcessorLevel == 3) {
      do {
        uVar2 = *(undefined4 *)(local_8 + local_c * 4);
        *(uint *)(local_8 + local_c * 4) =
             (uint)CONCAT21(CONCAT11((char)uVar2,(char)((uint)uVar2 >> 8)),
                            (char)((uint)uVar2 >> 0x10));
        local_c = local_c + -1;
      } while (-1 < local_c);
    }
    else {
      do {
        uVar1 = *(uint *)(local_8 + local_c * 4);
        *(uint *)(local_8 + local_c * 4) =
             ((uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) >> 8;
        local_c = local_c + -1;
      } while (-1 < local_c);
    }
  }
  return;
}

