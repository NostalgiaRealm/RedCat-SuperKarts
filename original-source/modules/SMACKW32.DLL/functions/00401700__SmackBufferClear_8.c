/*
 * _SmackBufferClear@8 at 00401700
 * undefined __stdcall _SmackBufferClear@8(int param_1, undefined1 param_2)
 * Address ranges: 00401700-00401760
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackBufferClear_8(int param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint local_14;
  
                    /* 0x1700  8  _SmackBufferClear@8 */
  if (param_1 != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0x448);
    local_14 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        uVar2 = *(uint *)(param_1 + 0x10);
        puVar4 = puVar3;
        for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
          puVar4 = puVar4 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar4 = param_2;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        local_14 = local_14 + 1;
        puVar3 = (undefined4 *)((int)puVar3 + *(int *)(param_1 + 0x18));
      } while (local_14 < *(uint *)(param_1 + 0x14));
    }
  }
  return;
}

