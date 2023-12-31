union()
{
    rotate([0.0, 90.0, 0.0])
    {
        difference()
        {
            intersection()
            {
                difference()
                {
                    rotate_extrude(angle = 360.0, $fn = 128)
                    {
                        M119();
                    }
                    translate([0.0, 0.0, 2.0])
                    {
                        linear_extrude(height = 10.0, twist = 0.0, scale = 1.0, slices = 1, center = false)
                        {
                            scale([10.0, 1.6])
                            {
                                M22();
                            }
                        }
                    }
                }
                linear_extrude(height = 10.0, twist = 0.0, scale = 1.0, slices = 1, center = false)
                {
                    scale([5.0, 10.0])
                    {
                        M22();
                    }
                }
            }
            linear_extrude(height = 0.4, twist = 0.0, scale = 1.0, slices = 1, center = false)
            {
                translate([2.0, -2.3499999999999996])
                {
                    mirror([1.0, 0.0])
                    {
                        union()
                        {
                            translate([0.0, 0.0])
                            {
                                M48();
                            }
                        }
                    }
                }
            }
        }
    }
    translate([1.0, 0.0, 0.0])
    {
        rotate([0.0, 180.0, 0.0])
        {
            rotate([0.0, 90.0, 0.0])
            {
                difference()
                {
                    intersection()
                    {
                        difference()
                        {
                            rotate_extrude(angle = 360.0, $fn = 128)
                            {
                                M119();
                            }
                            translate([0.0, 0.0, 2.0])
                            {
                                linear_extrude(height = 10.0, twist = 0.0, scale = 1.0, slices = 1, center = false)
                                {
                                    scale([10.0, 1.6])
                                    {
                                        M22();
                                    }
                                }
                            }
                        }
                        linear_extrude(height = 10.0, twist = 0.0, scale = 1.0, slices = 1, center = false)
                        {
                            scale([5.0, 10.0])
                            {
                                M22();
                            }
                        }
                    }
                    linear_extrude(height = 0.4, twist = 0.0, scale = 1.0, slices = 1, center = false)
                    {
                        translate([2.0, -2.3499999999999996])
                        {
                            mirror([1.0, 0.0])
                            {
                                union()
                                {
                                    translate([0.0, 0.0])
                                    {
                                        M48();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

module M48()
{
    scale([0.5333333333333333, 0.5333333333333333])
    {
        text
        (
            text = "T",
            size = 10.0,
            font = "Consolas:style=Regular",
            halign = "left",
            valign = "baseline",
            spacing = 1.0,
            direction = "ltr",
            language = "en",
            script = "latin",
            $fn = 64
        );
    }
}

module M22()
{
    polygon
    (
        points =
        [
            [-0.5, -0.5], 
            [0.5, -0.5], 
            [0.5, 0.5], 
            [-0.5, 0.5]
        ],
        paths =
        [
            [0, 1, 2, 3]
        ]
    );
}

module M119()
{
    polygon
    (
        points =
        [
            [0.0, 0.2], 
            [3.9, 0.2], 
            [3.9, 1.4], 
            [2.9, 2.4], 
            [2.9, 7.3999999999999995], 
            [3.9, 8.4], 
            [2.9, 9.8], 
            [0.0, 9.8], 
            [0.0, 1.8]
        ],
        paths =
        [
            [0, 1, 2, 3, 4, 5, 6, 7, 8]
        ]
    );
}
