/*
 * FUN_0041ee10 at 0041ee10
 * undefined __thiscall FUN_0041ee10(void * this, undefined4 param_1)
 * Address ranges: 0041ee10-0041ee2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041ee10(void *this,undefined4 param_1)

{
  if (*(char *)((int)this + 4) != '\0') {
    (**(code **)(*(int *)this + 0x20))();
  }
  (*(code *)**(undefined4 **)this)(param_1);
  return;
}

