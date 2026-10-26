/*
 * FUN_0040c32a at 0040c32a
 * undefined4 __thiscall FUN_0040c32a(void * this, int param_1)
 * Address ranges: 0040c32a-0040c43c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040c32a(void *this,int param_1)

{
  int iVar1;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00432010);
  }
  iVar1 = *(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20);
  if (iVar1 == 2) {
    if (*(int *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) != 0) {
      *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 0;
      (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20) + 8))
                (*(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20));
    }
  }
  else if (iVar1 == 4) {
    if (*(int *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) != 0) {
      *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 0;
      FUN_0041fd93(*(LPVOID *)(DAT_0043d6e8 + param_1 * 0x20));
    }
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_alloc_type__d_f_00432050);
  }
  return 0;
}

