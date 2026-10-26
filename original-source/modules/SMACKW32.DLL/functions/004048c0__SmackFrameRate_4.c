/*
 * _SmackFrameRate@4 at 004048c0
 * undefined __stdcall _SmackFrameRate@4(int param_1)
 * Address ranges: 004048c0-004048e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackFrameRate_4(int param_1)

{
                    /* 0x48c0  16  _SmackFrameRate@4 */
  if (0 < param_1) {
    param_1 = (int)(100000 / (longlong)-param_1);
  }
  DAT_0040e848 = param_1;
  return;
}

