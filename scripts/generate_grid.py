#!/usr/bin/env python
"""
Script to keep track of completed questions in a grid image.

Generates an image of a grid with n elements, such that elements corresponding to numbers passed in through stdin are colored.
"""
import argparse
import sys

from PIL import Image, ImageDraw

CELL_SIZE = 50
BG_COL = "black"
COMPLETE_FG_COL = "green"
INCOMPLETE_FG_COL = "white"
OUTLINE_COL = "black"


def closest_factor_pair(n: int, ratio: float) -> tuple([int, int]):
    factors = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            factors.append((n // i, i))

    closest_pair = factors[0]
    min_difference = abs(closest_pair[0] / closest_pair[1] - ratio)

    for pair in factors[1:]:
        current_difference = abs(pair[0] / pair[1] - ratio)
        if current_difference < min_difference:
            closest_pair = pair
            min_difference = current_difference

    return closest_pair


def generate_grid(n: int, nums: list[int], ratio: float) -> Image:
    width, height = closest_factor_pair(n, ratio)

    grid_width = width * CELL_SIZE
    grid_height = height * CELL_SIZE

    image = Image.new("RGB", (grid_width, grid_height), BG_COL)
    draw = ImageDraw.Draw(image)

    for i in range(width):
        for j in range(height):
            x = i * CELL_SIZE
            y = j * CELL_SIZE

            cell_index = i + j * width

            if cell_index in nums:
                draw.rectangle(
                    (x, y, x + CELL_SIZE, y + CELL_SIZE),
                    fill=COMPLETE_FG_COL,
                    outline=OUTLINE_COL,
                )
            else:
                draw.rectangle(
                    (x, y, x + CELL_SIZE, y + CELL_SIZE),
                    fill=INCOMPLETE_FG_COL,
                    outline=OUTLINE_COL,
                )

    return image


def main():
    parser = argparse.ArgumentParser(
        description="Script to keep track of completed questions in a grid image.",
        prog="GenerateGrid",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("-n", help="Number of elements in grid")
    parser.add_argument("-r", help="Width/Height ratio of grid", default=2)
    parser.add_argument("-o", help="File path to save image to", default="grid.png")
    args = parser.parse_args()
    config = vars(args)

    o = config.get("o")
    n = int(config.get("n"))
    r = float(config.get("r"))

    nums = [int(x) - 1 for x in sys.stdin]

    image = generate_grid(n, nums, r)
    image.save(o)


if __name__ == "__main__":
    main()
