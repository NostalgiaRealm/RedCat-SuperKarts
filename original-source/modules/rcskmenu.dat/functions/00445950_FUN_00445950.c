/*
 * FUN_00445950 at 00445950
 * undefined __register FUN_00445950(int param_1, char param_2)
 * Address ranges: 00445950-004459ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445950(int param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_2 != *(char *)(param_1 + 0x174)) {
    *(char *)(param_1 + 0x174) = param_2;
    bVar1 = FUN_00445a20(param_1);
    if (bVar1) {
      uVar2 = GetWindowLongA(*(HWND *)(param_1 + 0x14c),-0x10);
      uVar2 = uVar2 & 0xfffeffff;
      if (param_2 != '\0') {
        uVar2 = uVar2 | 0x10000;
      }
      SetWindowLongA(*(HWND *)(param_1 + 0x14c),-0x10,uVar2);
    }
    FUN_004405f0(param_1,0xb028,0,0);
  }
  return;
}

